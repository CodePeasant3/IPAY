#ifndef KEYBOARDOPERATION_H
#define KEYBOARDOPERATION_H
#include <QGuiApplication>
#include <windows.h>
#include <iostream>
#include <thread>

#include "savesettingstruct.h"
class KeyboardOperation
{
public:
    KeyboardOperation();
    void OperationKeyboard(std::vector<ipay::KeyboardMouseRecordStruct>& recordKeyboardVector);
    void MouseOperation(int x , int y, bool flags);
    void KeyOperation(const ipay::KeyboardMouseRecordStruct& keyRecord);
};

#endif // KEYBOARDOPERATION_H
