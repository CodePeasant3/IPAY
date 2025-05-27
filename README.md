131534253629958737
# 编译
目标机: Windows7-32bit

编译类型: Release

# 打包
在Windows11-64bit下打包32bit程序

1. 打开命令行**Developer Command Prompt for VS 2022**(包含了环境变量`VCINSTALLDIR`)
2. 在该命令行中进入程序的安装路径, 例如`C:/Users/juhao/Desktop/IPAY/build/Desktop_Qt_5_15_2_MSVC2019_32bit-Release/install`
3. 运行`windeployqt --release --compiler-runtime IPAY.exe`即可将依赖(dll以及运行库)全部复制到该目录下

# 运行
在目标机器(Windows7-32bit)上运行时
1. 双击`vc_redist.x86.exe`安装运行时环境
2. 双击`IPAY.exe`进行运行
3. 若需要查看日志请使用, 请打开`CMD`命令行窗口, 进入到安装目录下运行`IPAY.exe --console`

