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

void GenericUtil::CaptureScreen(const ipay::CashRegisterSettingStruct &cash_register_setting_struct,ScreenCaptureData& screenCaptureData)
{
    screenCaptureData.length = 0;
    if(cash_register_setting_struct.screen_w == 0 || cash_register_setting_struct.screen_h == 0){
        QMessageBox::warning(nullptr, "警告", "未设置识别框区域,请检查！");
        qDebug() << "picture infomation error w: "<< cash_register_setting_struct.screen_w << ", h:" << cash_register_setting_struct.screen_h;
        return;
    }
     // 获取主屏幕
     QScreen *screen = QGuiApplication::primaryScreen();
     if (!screen) {
         QMessageBox::critical(nullptr, "错误", "获取电脑屏幕失败，请检查当前系统操作环境。");
         qDebug() << "Can't not get main screen";
         return;
     }

     QPixmap screenshot = screen->grabWindow(0, cash_register_setting_struct.screen_x, cash_register_setting_struct.screen_y, cash_register_setting_struct.screen_w, cash_register_setting_struct.screen_h);

     if (screenshot.isNull()) {
         QMessageBox::critical(nullptr, "错误", "获取图像数据失败，请检查当前系统操作环境。");
         qDebug() << "get main screen picture failed!";
         return;
     }

    QImage image = screenshot.toImage();
    screenCaptureData.format = image.format();
    screenCaptureData.length = image.sizeInBytes();
    screenCaptureData.data = new uchar[screenCaptureData.length];
    std::memcpy(screenCaptureData.data,image.bits(),image.sizeInBytes());
    screenCaptureData.width = cash_register_setting_struct.screen_w;
    screenCaptureData.height = cash_register_setting_struct.screen_h;

}







}
