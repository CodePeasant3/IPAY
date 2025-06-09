#include <iostream>
#include <Common/snowflake.hpp>
#include <QString>
#include <QDateTime>
#include <QMutex>
#include <QThread> // 添加QThread头文件

int main(int argc, char** argv) {
    // 生成ID（默认数据中心ID和机器ID）
    QString id1 = Snowflake::instance().nextId();

    std::cout << "snow: " << id1.toStdString() << std::endl;
    return 0;
}
