#include "httpsrequest.h"
#include <chrono>
#include <sstream>
#include <iomanip>
#include <Common/logging.h>
#include <Common/dbops.h>

#include <QJsonObject>
#include <QJsonDocument>
#include <QSslConfiguration>
#include <string>
#include "snowflake.hpp"

#define DEFAULT_URL_PAY "https://pay.zhuceyiyou.com/api/pay/unifiedOrder"
#define DEFAULT_URL_REFUND "https://pay.zhuceyiyou.com/api/refund/refundOrder"
#define DEFAULT_URL_QUERY_PAY "https://pay.zhuceyiyou.com/api/pay/query"
#define DEFAULT_URL_QUERY_REFUND "https://pay.zhuceyiyou.com/api/refund/query"
#define DEFAULT_MCHNO "00000001"
#define DEFAULT_APPID "00000002"
#define DEFAULT_KEY "000000"

int HttpsRequest::init(const QSettings& settings, DBOps* ops_ptr) {

    m_db_ops = ops_ptr;
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
    this->m_key =
        settings.value("Business/Key", DEFAULT_KEY).toString();


    qInfo(IPAY) << "mchNo: " << m_mchNo;
    qInfo(IPAY) << "appId: " << m_appId;
    qInfo(IPAY) << "url_pay: " << url_pay;
    qInfo(IPAY) << "url_refund: " << url_refund;
    qInfo(IPAY) << "url_query_pay: " << url_query_pay;
    qInfo(IPAY) << "url_query_refund: " << url_query_refund;
    qInfo(IPAY) << "m_key: " << m_key;

    request_pay.setUrl(url_pay);
    request_refund.setUrl(url_refund);
    request_query_pay.setUrl(url_query_pay);
    request_query_refund.setUrl(url_query_refund);
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

 // 生成退款编号 M 27210 63210 0491
std::string HttpsRequest::generateRefundNo() {
    QString id1 = Snowflake::instance().nextId();
    return id1.toStdString();
}


// 生成商户订单号
std::string HttpsRequest::generateOrderNo() {
    QString id1 = Snowflake::instance().nextId();
    return id1.toStdString();
}


int HttpsRequest::pay(const std::string& auth_code , const std::string& amount) {
    if(m_mchNo.isEmpty() || m_appId.isEmpty() || url_pay.isEmpty()) {
        qWarning(IPAY) << "m_mchNo.isEmpty() or m_appId.isEmpty() or url_pay.isEmpty()";
        return -1;
    }

    QUrlQuery postData;
    std::map<std::string, std::string> body_data;

    std::string strip_str = this->stripZero(amount);
    body_data["amount"] = strip_str; //金额
    body_data["mchNo"] = m_mchNo.toStdString();
    body_data["appId"] = m_appId.toStdString();

    body_data["mchOrderNo"] = generateOrderNo(); // 商户生成的订单号
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

    source_str += "&key=";
    source_str += m_key.toStdString();
    qDebug(IPAY) << "原始字符串: " << source_str.c_str();
    std::string sign_str = generateMD5(source_str);
    postData.addQueryItem("sign", sign_str.c_str());

    std::string final_str = addPoint(amount);
    qInfo(IPAY) << "fianl_str: " << final_str.c_str();
    return this->postRequest(request_pay, final_str, std::move(postData));
}

int HttpsRequest::refund(const std::string& pay_order_id, const std::string& refundAmount) {
    qInfo(IPAY) << "-------> refund";
    if(m_mchNo.isEmpty() || m_appId.isEmpty() || url_refund.isEmpty()) {
        qWarning(IPAY) << "m_mchNo.isEmpty() or m_appId.isEmpty() or url_refund.isEmpty()";
        return -1;
    }

    QUrlQuery postData;
    std::map<std::string, std::string> body_data;
    body_data["mchNo"] = m_mchNo.toStdString();
    body_data["appId"] = m_appId.toStdString();
    body_data["refundAmount"] = refundAmount;

    body_data["payOrderId"] = pay_order_id;
    body_data["mchRefundNo"] = this->generateRefundNo();
    body_data["reqTime"] = get_utc_timestamp();


    // 固定
    body_data["currency"] = "cny"; // 人民币
    body_data["refundReason"] = "NO_REASON"; // 退款原因
    body_data["version"] = "1.0"; // 固定版本
    body_data["signType"] = "MD5"; // 摘要算法
    body_data["subject"] = "GOODS_TITLE"; // 商品标题
    body_data["body"] = "GOODS_DESCRIPTION"; // 商品描述
    // body_data["channelExtra"] = "";


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

    source_str += "&key=";
    source_str += m_key.toStdString();
    qDebug(IPAY) << "退款原始字符串: " << source_str.c_str();
    std::string sign_str = generateMD5(source_str);
    qDebug(IPAY) << "退款sign: " << sign_str.c_str();
    postData.addQueryItem("sign", sign_str.c_str());

    return this->refundPostRequest(request_refund, refundAmount, std::move(postData));

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


int HttpsRequest::postRequest(const QNetworkRequest& req, const std::string& amount, const QUrlQuery&& post_data) {
    QNetworkReply *reply = managerPost.post(req, post_data.toString(QUrl::FullyEncoded).toUtf8());
    // 同步等待请求完成（阻塞当前线程, 但是缺直接返回）
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    // 处理响应
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QJsonParseError parseError;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData, &parseError);
        if (jsonDoc.isNull()) {
            qWarning(IPAY) << "JSON解析错误:" << parseError.errorString();
            qWarning(IPAY) << "原始数据:" << responseData;
            return -1;
        }
        const auto& pay_order_id =
            jsonDoc["data"]["payOrderId"].toString();
        int order_type =
            jsonDoc["data"]["orderState"].toInt();
        qInfo(IPAY) << "replay >>> code: " << jsonDoc["code"].toInt();
        qInfo(IPAY) << "replay >>> mchOrderNo: " << jsonDoc["data"]["mchOrderNo"].toString();
        qInfo(IPAY) << "REPLAY >>> payOrderId: " << jsonDoc["data"]["payOrderId"].toString();
        qInfo(IPAY) << "REPLAY >>> orderState: " << jsonDoc["data"]["orderState"].toInt();

        // INFO: insert db;
        this->m_db_ops->insertData(pay_order_id, 1, pay_order_id, amount.c_str(), order_type);
        return 0;
    } else {
        qWarning(IPAY) << "请求错误:" << reply->errorString();
        // TODO insert db;
        reply->deleteLater();
        return -1;
    }
    return -2;
}

int HttpsRequest::refundPostRequest(const QNetworkRequest& req,const std::string& amount, const QUrlQuery&& post_data) {
    QNetworkReply *reply = managerPost.post(req, post_data.toString(QUrl::FullyEncoded).toUtf8());
    // 同步等待请求完成（阻塞当前线程, 但是缺直接返回）
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QJsonParseError parseError;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData, &parseError);
        if (jsonDoc.isNull()) {
            qWarning(IPAY) << "JSON解析错误:" << parseError.errorString();
            qWarning(IPAY) << "原始数据:" << responseData;
            return -1;
        }
        qWarning(IPAY) << "原始数据:" << responseData;

        return 0;
    } else {
        qWarning(IPAY) << "请求错误:" << reply->errorString();
        // TODO insert db;
        reply->deleteLater();
        return -1;
    }
    return -2;

    return 0;
}
std::string HttpsRequest::stripZero(const std::string& str) {
    size_t firstNonZero = str.find_first_not_of('0');
    if (firstNonZero == std::string::npos) {
        return "0";
    }
    return str.substr(firstNonZero);
}


std::string HttpsRequest::addPoint(const std::string& str) {
    if (str.length() < 3) {
        return str;
    }

    size_t insertPos = str.length() - 2;
    return str.substr(0, insertPos) + "." + str.substr(insertPos);
}
