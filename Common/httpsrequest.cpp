#include "httpsrequest.h"
#include <chrono>
#include <sstream>
#include <iomanip>

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



HttpsRequest::HttpsRequest() {
    // TOOD 获取商户号和应用ID
    this->m_mchNo = "TODO";
    this->m_appId = "TODO";

    this->url_pay = "http://pay.zhuceyiyou.com/api/pay/unifiedOrder";
    this->url_refund = "http://pay.zhuceyiyou.com/api/refund/refundOrder";
    this->url_query_pay = "http://pay.zhuceyiyou.com/api/pay/query";
    this->url_query_refund = "http://pay.zhuceyiyou.com/api/refund/query";

     request_pay.setUrl(QUrl(url_pay.c_str()));
     request_pay.setRawHeader("accept", "*/*");
     request_pay.setRawHeader("Accept-Language", "zh-CN");
     request_pay.setRawHeader("Content-Type", "application/json;charset=UTF-8");

     request_refund.setUrl(QUrl(url_refund.c_str()));
     request_refund.setRawHeader("accept", "*/*");
     request_refund.setRawHeader("Accept-Language", "zh-CN");
     request_refund.setRawHeader("Content-Type", "application/json;charset=UTF-8");

     request_query_pay.setUrl(QUrl(url_query_pay.c_str()));
     request_query_pay.setRawHeader("accept", "*/*");
     request_query_pay.setRawHeader("Accept-Language", "zh-CN");
     request_query_pay.setRawHeader("Content-Type", "application/json;charset=UTF-8");

     request_query_refund.setUrl(QUrl(url_query_refund.c_str()));
     request_query_refund.setRawHeader("accept", "*/*");
     request_query_refund.setRawHeader("Accept-Language", "zh-CN");
     request_query_refund.setRawHeader("Content-Type", "application/json;charset=UTF-8");


}

int HttpsRequest::pay(const std::string& amount) {
    QUrlQuery postData;
    std::map<std::string, std::string> body_data;

    body_data["amount"] = amount; //金额
    body_data["mchNo"] = m_mchNo;
    body_data["appId"] = m_appId;

    body_data["mchOrderNo"] = generateOrderNo(); // 商户生成的订单号
    body_data["channelExtra"] = "TODO";
    body_data["reqTime"] = get_utc_timestamp();

    // 固定值
    body_data["version"] = "1.0"; // 固定版本
    body_data["signType"] = "MD5"; // 摘要算法
    body_data["wayCode"] = "AUTO_BAR"; // 融合支付
    body_data["currency"] = "cny"; // 人民币
    body_data["subject"] = "GOODS_TITLE"; // 商品标题
    body_data["body"] = "GOODS_DESCRIPTION"; // 商品描述

    for(const auto& ele : body_data) {
        postData.addQueryItem(ele.first.c_str(), ele.second.c_str());
    }

    const QString& body_str = postData.toString(QUrl::FullyEncoded).toUtf8();
    qDebug() << body_str;
    body_data["sign"] = generateMD5(body_str.toStdString());

    // const auto& replay = managerPost.post(request_pay, postData.toString(QUrl::FullyEncoded).toUtf8());
    // qDebug() << replay->readAll();

    return 0;
}

int HttpsRequest::refund(const std::string& refundAmount) {
    QUrlQuery postData;
    std::map<std::string, std::string> body_data;
    body_data["mchNo"] = m_mchNo;
    body_data["appId"] = m_appId;
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

    // const auto& replay = managerPost.post(request_refund, postData.toString(QUrl::FullyEncoded).toUtf8());
    // qDebug() << replay->readAll();

    return 0;
}

int HttpsRequest::query_pay() {
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
    QUrlQuery postData;
    std::map<std::string, std::string> body_data;
    for(const auto& ele : body_data) {
        postData.addQueryItem(ele.first.c_str(), ele.second.c_str());
    }

    // const auto& replay = managerPost.post(request_query_refund, postData.toString(QUrl::FullyEncoded).toUtf8());
    // qDebug() << replay->readAll();
    return 0;
}
