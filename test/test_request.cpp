#include <iostream>
#include <httpsrequest.h>

int main(int argc, char** argv) {
    // 检查Qt是否支持SSL
    if (!QSslSocket::supportsSsl()) {
        qDebug() << "Qt不支持SSL，请检查编译配置";
        return 0;
    }
    return 0;

}
