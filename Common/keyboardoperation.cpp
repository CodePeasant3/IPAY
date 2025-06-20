﻿#include "keyboardoperation.h"

namespace ipay {
KeyboardOperation::KeyboardOperation()
{

}

void KeyboardOperation::OperationKeyboard(std::vector<ipay::KeyboardMouseRecordStruct>& recordKeyboardVector,int interaval)
{

    for (auto keyboardOperation :  recordKeyboardVector) {
        QThread::msleep(100);
        if(keyboardOperation.type == ipay::KeyboardMouseType::LIFTMOUSE){
            MouseOperation(keyboardOperation.mouse_x,keyboardOperation.mouse_y,true,interaval);
        }
        else if(keyboardOperation.type == ipay::KeyboardMouseType::RIGHTMOUSE){
            MouseOperation(keyboardOperation.mouse_x,keyboardOperation.mouse_y,false,interaval);
        }
        else if(keyboardOperation.type == ipay::KeyboardMouseType::KETBOARD){
            KeyOperation(keyboardOperation,interaval);
        }
    }



}

void KeyboardOperation::MouseOperation(int x, int y , bool flags,int interaval)
{
    SetCursorPos(x, y);

    mouse_event(flags ? MOUSEEVENTF_LEFTDOWN : MOUSEEVENTF_RIGHTDOWN, x, y, 0, 0);

    std::this_thread::sleep_for(std::chrono::milliseconds(interaval < 20 ? 20 : interaval));

    mouse_event(flags ? MOUSEEVENTF_LEFTUP : MOUSEEVENTF_RIGHTUP, x, y, 0, 0);

}

void KeyboardOperation::KeyOperation(const ipay::KeyboardMouseRecordStruct& keyRecord,int interaval)
{

    INPUT input = {0};
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = static_cast<WORD>(keyRecord.key_num);
    SendInput(1, &input, sizeof(INPUT));

    std::this_thread::sleep_for(std::chrono::milliseconds(interaval < 20 ? 20 : interaval));

    ZeroMemory(&input, sizeof(INPUT));
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = static_cast<WORD>(keyRecord.key_num);
    input.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(INPUT));





}

}
