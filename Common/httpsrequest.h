#ifndef HTTPSREQUEST_H
#define HTTPSREQUEST_H

#include <QtNetwork/QtNetwork>
#include <QtNetwork/QNetworkAccessManager>
#include <QtCore/QCryptographicHash>

class HttpsRequest
{
public:
    int init(const QSettings& settings);
    int pay(const std::string& amount); // 收款
    int refund(const std::string& refundAmount); // 退款
    int query_pay(); // 查询付款订单状态
    int query_refund(); // 查询退款订单状态

private:
    QNetworkAccessManager managerPost;
    QNetworkRequest request_pay;
    QNetworkRequest request_refund;
    QNetworkRequest request_query_pay;
    QNetworkRequest request_query_refund;

private:
    std::string generateMD5(const std::string& text);
    std::string get_utc_timestamp();
    std::string generateOrderNo();
    QString m_mchNo; // 商户号
    QString m_appId; // 应用ID
    QString url_pay;
    QString url_refund;
    QString url_query_pay;
    QString url_query_refund;
};

#endif // HTTPSREQUEST_H
