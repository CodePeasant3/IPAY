#include "httpsrequest.h"
#include <chrono>
#include <sstream>
#include <iomanip>
#include <Common/logging.h>

#include <QJsonObject>
#include <QJsonDocument>
#include <QSslConfiguration>

#define DEFAULT_URL_PAY "https://pay.zhuceyiyou.com/api/pay/unifiedOrder"
#define DEFAULT_URL_REFUND "https://pay.zhuceyiyou.com/api/refund/refundOrder"
#define DEFAULT_URL_QUERY_PAY "https://pay.zhuceyiyou.com/api/pay/query"
#define DEFAULT_URL_QUERY_REFUND "https://pay.zhuceyiyou.com/api/refund/query"
#define DEFAULT_MCHNO "00000001"
#define DEFAULT_APPID "00000002"

int HttpsRequest::init(const QSettings& settings) {

    this->url_pay =
        settings.value("Payment/UrlPay", DEFAULT_URL_PAY).toString();
    this->url_refund =
        settings.value("Payment/UrlRefund", DEFAULT_URL_REFUND).toString();
    this->url_query_pay =
        settings.value("Payment/UrlQueryPay", DEFAULT_URL_QUERY_PAY).toString();
    this->url_query_refund =
        settings.value("Payment/UrlQueryRefund", DEFAULT_URL_QUERY_REFUND).toString();
    this->m_mchNo =
        settings.value("Business/mchNo", DEFAULT_MCHNO).toString();
    this->m_appId =
        settings.value("Business/appId", DEFAULT_APPID).toString();

    qInfo(IPAY) << "mchNo: " << m_mchNo;
    qInfo(IPAY) << "appId: " << m_appId;
    qInfo(IPAY) << "url_pay: " << url_pay;
    qInfo(IPAY) << "url_refund: " << url_refund;
    qInfo(IPAY) << "url_query_pay: " << url_query_pay;
    qInfo(IPAY) << "url_query_refund: " << url_query_refund;

    request_pay.setUrl(url_pay);


    // request_pay.setRawHeader("accept", "*/*");
    //request_pay.setRawHeader("Accept-Language", "zh-CN");
    // request_pay.setRawHeader("Content-Type", "application/json;charset=UTF-8");

    // request_pay.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    // request_pay.setHeader(QNetworkRequest::UserAgentHeader, "MyApp/1.0");


    request_refund.setUrl(url_refund);
    request_refund.setRawHeader("accept", "*/*");
    request_refund.setRawHeader("Accept-Language", "zh-CN");
    request_refund.setRawHeader("Content-Type", "application/json;charset=UTF-8");

    request_query_pay.setUrl(url_query_pay);
    request_query_pay.setRawHeader("accept", "*/*");
    request_query_pay.setRawHeader("Accept-Language", "zh-CN");
    request_query_pay.setRawHeader("Content-Type", "application/json;charset=UTF-8");

    request_query_refund.setUrl(url_query_refund);
    request_query_refund.setRawHeader("accept", "*/*");
    request_query_refund.setRawHeader("Accept-Language", "zh-CN");
    request_query_refund.setRawHeader("Content-Type", "application/json;charset=UTF-8");
    return 0;
}


// 获取13位UTC时间戳（毫秒级）
std::string HttpsRequest::get_utc_timestamp() {
    using namespace std::chrono;
    auto count = duration_cast<milliseconds>(
               system_clock::now().time_since_epoch()
               ).count();
    return std::to_string(count);
}

std::string HttpsRequest::generateMD5(const std::string& text) {
    QCryptographicHash md(QCryptographicHash::Md5);
    md.addData(text.c_str());
    QString md5_str = md.result().toHex().toUpper();
    return md5_str.toStdString();
}

std::string HttpsRequest::generateAuthCode(const std::string& text) {
    QJsonObject obj;
    obj["authCode"] = text.c_str();

    QJsonDocument doc(obj);
    return doc.toJson(QJsonDocument::Compact).toStdString();
}


// 生成商户订单号
std::string HttpsRequest::generateOrderNo() {
    // 20位
    // 2016 0427 21-06-04 000 490 // 精确到了微秒
    // 2025 0509 16-29-17 595 249
    // 2025 0510 00-46-53 538 538
    QDateTime currentUtcTime = QDateTime::currentDateTimeUtc();
    QTimeZone beijingTimeZone("Asia/Shanghai");
    QDateTime beijingTime = currentUtcTime.toTimeZone(beijingTimeZone);
    auto time_ret = beijingTime.toString("yyyyMMddHHmmsszzzzzz"); // 修复：使用HH表示24小时制
    qDebug() << "北京时间:" << time_ret;
    return time_ret.toStdString();
}


int HttpsRequest::pay(const std::string& auth_code , const std::string& amount) {
    if(m_mchNo.isEmpty() || m_appId.isEmpty() || url_pay.isEmpty()) {
        qWarning() << "m_mchNo.isEmpty() or m_appId.isEmpty() or url_pay.isEmpty()";
        return -1;
    }

    QUrlQuery postData;
    std::map<std::string, std::string> body_data;


    body_data["amount"] = amount; //金额
    body_data["mchNo"] = m_mchNo.toStdString();
    body_data["appId"] = m_appId.toStdString();

    body_data["mchOrderNo"] = generateOrderNo(); // 商户生成的订单号
    // body_data["channelExtra"] = "TODO";
    body_data["reqTime"] = get_utc_timestamp();
    body_data["channelExtra"] = generateAuthCode(auth_code);


    // 固定值
    body_data["version"] = "1.0"; // 固定版本
    body_data["signType"] = "MD5"; // 摘要算法
    body_data["wayCode"] = "AUTO_BAR"; // 融合支付
    body_data["currency"] = "cny"; // 人民币
    body_data["subject"] = "GOODS_TITLE"; // 商品标题
    body_data["body"] = "GOODS_DESCRIPTION"; // 商品描述

    std::string source_str = {};
    for(const auto& ele : body_data) {
        postData.addQueryItem(ele.first.c_str(), ele.second.c_str());
        if(source_str.size() != 0) {
            source_str += "&";
        }
        source_str += ele.first;
        source_str += "=";
        source_str += ele.second;
    }
    // postData.addQueryItem("key", "qd248nS36L8ajWkR8NdujGGRV5RLSO6CMsfTI192qGh52p9J5HqVsJazjmvbo59wn4c0vWOUTMoEYuk31Y8lxyHkzfsPuhg5RsuFSbBMtGmeKqwJQPhsS044fNHgZtzx");
    source_str += "&key=qd248nS36L8ajWkR8NdujGGRV5RLSO6CMsfTI192qGh52p9J5HqVsJazjmvbo59wn4c0vWOUTMoEYuk31Y8lxyHkzfsPuhg5RsuFSbBMtGmeKqwJQPhsS044fNHgZtzx";

    qDebug(IPAY) << "原始字符串: " << source_str.c_str();
    std::string sign_str = generateMD5(source_str);
    // postData.removeQueryItem("key");
    postData.addQueryItem("sign", sign_str.c_str());


    QNetworkReply *reply = managerPost.post(request_pay, postData.toString(QUrl::FullyEncoded).toUtf8());
    qWarning(IPAY) << ">>>>> READAll:";

    // 同步等待请求完成（阻塞当前线程）
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    // 处理响应
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        qDebug(IPAY) << "响应数据:" << QString::fromUtf8(responseData);
    } else {
        qDebug(IPAY) << "请求错误:" << reply->errorString();
    }

    reply->deleteLater();

    return 0;
}

int HttpsRequest::refund(const std::string& refundAmount) {
    if(m_mchNo.isEmpty() || m_appId.isEmpty() || url_refund.isEmpty()) {
        qWarning() << "m_mchNo.isEmpty() or m_appId.isEmpty() or url_refund.isEmpty()";
        return -1;
    }

    QUrlQuery postData;
    std::map<std::string, std::string> body_data;
    body_data["mchNo"] = m_mchNo.toStdString();
    body_data["appId"] = m_appId.toStdString();
    body_data["refundAmount"] = refundAmount;

    body_data["mchOrderNo"] = "TODO";
    body_data["payOrderId"] = "TODO";
    body_data["mchRefundNo"] = "TODO";
    body_data["channelExtra"] = "TODO";
    body_data["reqTime"] = get_utc_timestamp();


    // 固定
    body_data["currency"] = "cny"; // 人民币
    body_data["refundReason"] = "CUSTOMER"; // 退款原因
    body_data["version"] = "1.0"; // 固定版本
    body_data["signType"] = "MD5"; // 摘要算法

    for(const auto& ele : body_data) {
        postData.addQueryItem(ele.first.c_str(), ele.second.c_str());
    }
    const QString& body_str = postData.toString(QUrl::FullyEncoded).toUtf8();
    body_data["sign"] = generateMD5(body_str.toStdString());

    const auto& replay = managerPost.post(request_refund, postData.toString(QUrl::FullyEncoded).toUtf8());
    qWarning(IPAY) << ">>>>> READAll:";
    qWarning(IPAY) << replay->readAll();

    return 0;
}

int HttpsRequest::query_pay() {
    if(m_mchNo.isEmpty() || m_appId.isEmpty() || url_query_pay.isEmpty()) {
        qWarning() << "m_mchNo.isEmpty() or m_appId.isEmpty() or url_query_pay.isEmpty()";
        return -1;
    }

    QUrlQuery postData;
    std::map<std::string, std::string> body_data;
    for(const auto& ele : body_data) {
        postData.addQueryItem(ele.first.c_str(), ele.second.c_str());
    }
    // const auto& replay = managerPost.post(request_query_pay, postData.toString(QUrl::FullyEncoded).toUtf8());
    // qDebug() << replay->readAll();
    return 0;
}


int HttpsRequest::query_refund() {
    if(m_mchNo.isEmpty() || m_appId.isEmpty() || url_query_refund.isEmpty()) {
        qWarning() << "m_mchNo.isEmpty() or m_appId.isEmpty() or url_query_refund.isEmpty()";
        return -1;
    }

    QUrlQuery postData;
    std::map<std::string, std::string> body_data;
    for(const auto& ele : body_data) {
        postData.addQueryItem(ele.first.c_str(), ele.second.c_str());
    }

    // const auto& replay = managerPost.post(request_query_refund, postData.toString(QUrl::FullyEncoded).toUtf8());
    // qDebug() << replay->readAll();
    return 0;
}
