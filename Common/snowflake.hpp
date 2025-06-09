#pragma once

#include <QString>
#include <QDateTime>
#include <QMutex>
#include <QThread> // 添加QThread头文件

class Snowflake {
public:
    // 单例模式获取实例
    static Snowflake& instance(quint64 datacenterId = 1, quint64 machineId = 1) {
        static Snowflake instance(datacenterId, machineId);
        return instance;
    }

    // 生成下一个唯一ID（字符串形式）
    QString nextId() {
        QMutexLocker locker(&mutex);

        qint64 now = QDateTime::currentMSecsSinceEpoch();

        // 处理时钟回拨
        if (now < lastTimestamp) {
            now = waitForNextMillis(lastTimestamp);
        }

        if (now == lastTimestamp) {
            sequence = (sequence + 1) & sequenceMask;
            if (sequence == 0) {
                now = waitForNextMillis(lastTimestamp);
            }
        } else {
            sequence = 0;
        }

        lastTimestamp = now;

        // 生成64位ID
        qint64 id = ((now - epoch) << timestampShift) |
                    (datacenterId << datacenterIdShift) |
                    (machineId << machineIdShift) |
                    sequence;

        return QString::number(id);
    }

private:
    // 使用static constexpr直接在类内初始化epoch
    static constexpr qint64 epoch = 1577836800000; // 2020-01-01 00:00:00 UTC

    Snowflake(quint64 dcId, quint64 mId)
        : datacenterId(dcId & maxDatacenterId),
        machineId(mId & maxMachineId),
        sequence(0),
        lastTimestamp(-1) {
        // epoch的初始化已经在类定义中完成，不需要在这里赋值
    }

    Snowflake(const Snowflake&) = delete;
    Snowflake& operator=(const Snowflake&) = delete;

    qint64 waitForNextMillis(qint64 lastTimestamp) {
        qint64 timestamp = QDateTime::currentMSecsSinceEpoch();
        while (timestamp <= lastTimestamp) {
            timestamp = QDateTime::currentMSecsSinceEpoch();
            QThread::msleep(1);
        }
        return timestamp;
    }

    // 基础配置
    const qint64 datacenterIdBits = 5;
    const qint64 machineIdBits = 5;
    const qint64 sequenceBits = 12;

    const qint64 maxDatacenterId = (1LL << datacenterIdBits) - 1;
    const qint64 maxMachineId = (1LL << machineIdBits) - 1;

    const qint64 timestampShift = sequenceBits + datacenterIdBits + machineIdBits;
    const qint64 datacenterIdShift = sequenceBits + machineIdBits;
    const qint64 machineIdShift = sequenceBits;
    const qint64 sequenceMask = (1LL << sequenceBits) - 1;

    // 工作状态
    const quint64 datacenterId;
    const quint64 machineId;
    quint64 sequence;
    qint64 lastTimestamp;

    // 线程安全
    QMutex mutex;
};
