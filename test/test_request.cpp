#include <iostream>
#include <httpsrequest.h>

int main(int argc, char** argv) {
    std::cerr << "Hello test_http_request" << std::endl;
    HttpsRequest request;
    request.pay("111");

}
