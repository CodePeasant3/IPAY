#include <iostream>
#include <QtNetwork/QtNetwork>
#include <QtNetwork/QNetworkAccessManager>
#include <QtCore/QCryptographicHash>

int main(int argc, char** argv) {
    qDebug() << "test_MD5";
    QNetworkAccessManager managerPost;
    QNetworkRequest reqPost;

    reqPost.setUrl(QUrl("http://pay.zhuceyiyou.com/api/pay/unifiedOrder"));
    reqPost.setRawHeader("accept", "*/*");
    reqPost.setRawHeader("Accept-Language", "zh-CN");
    reqPost.setRawHeader("Content-Type", "application/json;charset=UTF-8");

    QUrlQuery postData;
    // 字典序 需要自己确定addQueryItem顺序
    postData.addQueryItem("amount", "10000");
    postData.addQueryItem("clientIp", "192.168.0.111");
    postData.addQueryItem("mchOrderNo", "P0123456789101");
    postData.addQueryItem("platId", "1000");
    postData.addQueryItem("reqTime", "20190723141000");
    postData.addQueryItem("key", "EWEFD123RGSRETYDFNGFGFGSHDFGH");

    const auto& body_str = postData.toString(QUrl::FullyEncoded).toUtf8();
    qDebug() << "body_str: " << body_str;
    // 生成MD5指纹
    QCryptographicHash md(QCryptographicHash::Md5);
    md.addData(body_str.constData());
    QString md5_str = md.result().toHex();

    qDebug() << "body_str md5: " << md5_str.toUpper();

    const auto& replay = managerPost.post(reqPost,postData.toString(QUrl::FullyEncoded).toUtf8());
    qDebug() << replay->readAll();

    qDebug() << "test_MD5 END";


    return 0;
}

