#include <iostream>
#include <QJsonObject>
#include <QJsonDocument>

int main(int argc, char** argv) {
    QJsonObject person;
    person["auth_code"] = "13920933111042";


    QJsonDocument doc(person);
    auto dump_str = doc.toJson(QJsonDocument::Compact); // 紧凑格式，无缩进
    std::cout << dump_str.toStdString() << std::endl;
    return 0;
}
