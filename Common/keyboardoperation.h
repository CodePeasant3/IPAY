#ifndef KEYBOARDOPERATION_H
#define KEYBOARDOPERATION_H
#include <QGuiApplication>
#include <windows.h>
#include <iostream>
#include <thread>
#include <QThread>

#include "savesettingstruct.h"

namespace ipay {


class KeyboardOperation
{
public:
    KeyboardOperation();
    void OperationKeyboard(std::vector<ipay::KeyboardMouseRecordStruct>& recordKeyboardVector,int interaval);
    void MouseOperation(int x , int y, bool flags,int interaval);
    void KeyOperation(const ipay::KeyboardMouseRecordStruct& keyRecord,int interaval);
};

}


#endif // KEYBOARDOPERATION_H
