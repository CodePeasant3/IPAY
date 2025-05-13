#include <iostream>
#include <httpsrequest.h>

int main(int argc, char** argv) {
    std::cerr << "Hello test_http_request" << std::endl;
    HttpsRequest request;

    QSettings settings("../config.ini", QSettings::IniFormat);
    request.init(settings);

    request.pay("111");

}
