#ifndef HTTPSREQUEST_H
#define HTTPSREQUEST_H

#include <QtNetwork/QtNetwork>
#include <QtNetwork/QNetworkAccessManager>
#include <QtCore/QCryptographicHash>
#include "globalstatuscommon.h"
#include "keyboardoperation.h"
class DBOps;


class HttpsRequest
{
public:
    int init(const QSettings& settings, DBOps*);
    int pay(const std::string& auth_code, const std::string& amount); // 收款
    int refund(const std::string& pay_order_id, const std::string& refundAmount); // 退款
    int query_pay(const QString& pay_order_id); // 查询付款订单状态
    int query_refund(const QString& pay_order_id); // 查询退款订单状态
    int close_order(const QString& pay_order_id); // 关闭订单

private:
    QNetworkAccessManager managerPost;
    QNetworkRequest request_pay;
    QNetworkRequest request_refund;
    QNetworkRequest request_query_pay;
    QNetworkRequest request_query_refund;
    QNetworkRequest request_close_order;

private:
    std::string generateMD5(const std::string& text);
    std::string generateAuthCode(const std::string& text);
    std::string get_utc_timestamp();
    std::string generateOrderNo(); // 生成订单编号
    std::string generateRefundNo(); // 生成退款编号
    QString m_mchNo; // 商户号
    QString m_appId; // 应用ID
    QString url_pay;
    QString url_refund;
    QString url_query_pay;
    QString url_query_refund;
    QString url_close_order;
    QString m_key;
    DBOps* m_db_ops;

private:
    int postRequest(const QNetworkRequest& req, const std::string& amount, const QUrlQuery&& post_data);
    int refundPostRequest(const QNetworkRequest& req,const std::string& amount, const QUrlQuery&& post_data);
    std::string stripZero(const std::string& str);
    std::string addPoint(const std::string& str);
    int queryPayPostRequest(const QNetworkRequest& req, const std::string& pay_order_id, const QUrlQuery&& post_data);
    int queryRefundPostRequest(const QNetworkRequest& req, const std::string& pay_order_id, const QUrlQuery&& post_data);
    int closePostRequest(const QNetworkRequest& req, const std::string& pay_order_id, const QUrlQuery&& post_data);

};

#endif // HTTPSREQUEST_H
