#include "keyboardoperation.h"

KeyboardOperation::KeyboardOperation()
{

}

void KeyboardOperation::OperationKeyboard(std::vector<ipay::KeyboardMouseRecordStruct>& recordKeyboardVector)
{

    for (auto keyboardOperation :  recordKeyboardVector) {
        if(keyboardOperation.type == ipay::KeyboardMouseType::LIFTMOUSE){
            MouseOperation(keyboardOperation.mouse_x,keyboardOperation.mouse_y,true);
        }
        else if(keyboardOperation.type == ipay::KeyboardMouseType::RIGHTMOUSE){
            MouseOperation(keyboardOperation.mouse_x,keyboardOperation.mouse_y,false);
        }
        else if(keyboardOperation.type == ipay::KeyboardMouseType::KETBOARD){
            KeyOperation(keyboardOperation);
        }
    }



}

void KeyboardOperation::MouseOperation(int x, int y , bool flags)
{
    SetCursorPos(x, y);

    mouse_event(flags ? MOUSEEVENTF_LEFTDOWN : MOUSEEVENTF_RIGHTDOWN, x, y, 0, 0);

    std::this_thread::sleep_for(std::chrono::milliseconds(20));

    mouse_event(flags ? MOUSEEVENTF_LEFTUP : MOUSEEVENTF_RIGHTUP, x, y, 0, 0);

}

void KeyboardOperation::KeyOperation(const ipay::KeyboardMouseRecordStruct& keyRecord)
{

    INPUT input = {0};
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = static_cast<WORD>(keyRecord.key_num);
    SendInput(1, &input, sizeof(INPUT));

    std::this_thread::sleep_for(std::chrono::milliseconds(20));

    ZeroMemory(&input, sizeof(INPUT));
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = static_cast<WORD>(keyRecord.key_num);
    input.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(INPUT));





}
