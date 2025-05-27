#include <iostream>
#include <httpsrequest.h>

int main(int argc, char** argv) {
    // 检查Qt是否支持SSL
    if (!QSslSocket::supportsSsl()) {
        qDebug() << "Qt不支持SSL，请检查编译配置";
        return 0;
    }

    std::cerr << "Hello test_http_request" << std::endl;
    HttpsRequest request;

    QSettings settings("config.ini", QSettings::IniFormat);
    request.init(settings);

    // request.pay("111");

}
