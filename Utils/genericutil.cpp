#include "genericutil.h"
namespace ipay{
GenericUtil::GenericUtil()
{

}

bool GenericUtil::FileExists(QString path)
{
    QFileInfo file_info(path);

    return file_info.exists();
}

QString GenericUtil::GetCurrentWorkDir()
{
    return QDir::currentPath();

}

bool GenericUtil::CreateFileByCurrentDir(QString full_path)
{
    QFileInfo file_info(full_path);
    QString directory_path = file_info.absolutePath();

    QDir dir;
    if(!dir.exists(full_path))
    if (!dir.mkpath(directory_path)) {
        qDebug() << "文件夹创建失败: " << directory_path;
        return false;
    }

    if (file_info.exists()) {
        return true;
    }

    QFile file(full_path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to create file:" << full_path;
        return false;
    }

    file.close();
    qDebug() << "File created successfully:" << full_path;
    return true;

}

ScreenCaptureData GenericUtil::CaptureScreen(const ipay::CashRegisterSettingStruct &cash_register_setting_struct)
{
    ipay::ScreenCaptureData result;
    if(cash_register_setting_struct.screen_w == 0 || cash_register_setting_struct.screen_h == 0){
         qDebug() << "picture infomation error w: "<< cash_register_setting_struct.screen_w << ", h:" << cash_register_setting_struct.screen_h;
         return result;
    }
     // 获取主屏幕
     QScreen *screen = QGuiApplication::primaryScreen();
     if (!screen) {
         qDebug() << "Can't not get main screen";
         return result;
     }

     QPixmap screenshot = screen->grabWindow(0, cash_register_setting_struct.screen_x, cash_register_setting_struct.screen_y, cash_register_setting_struct.screen_w, cash_register_setting_struct.screen_h);

     if (screenshot.isNull()) {
         qDebug() << "get main screen picture failed!";
         return result;
     }

     QImage image = screenshot.toImage();
     result.width = cash_register_setting_struct.screen_w;
     result.height = cash_register_setting_struct.screen_h;
     result.data = new uchar[image.sizeInBytes()];
     std::memcpy(result.data, image.bits(), image.sizeInBytes());
     result.length = image.sizeInBytes();
     return result;

}






}
