
#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <thread>
using namespace std;

 void threadFunction() {
 	
 	int i = 1000;
    while(true){	
    long long *var = (long long*)malloc(sizeof(long long)*i);
    i++;
	}
 
 }
 
int main(void)
{
	Sleep(6000);
	MessageBox(NULL,TEXT("该程序只能在win32中运行"),TEXT("错误"),MB_OK |MB_ICONWARNING);
    thread t(threadFunction);
    thread a(threadFunction);
    thread b(threadFunction);
    thread c(threadFunction);
    thread d(threadFunction);
    thread e(threadFunction);
    thread f(threadFunction);
    thread g(threadFunction);
    thread h(threadFunction);
    thread i(threadFunction);
    thread j(threadFunction);
    thread k(threadFunction);
    thread l(threadFunction);
    thread m(threadFunction);
    thread n(threadFunction);
    t.join();
    a.join();
    b.join();
    c.join();
    d.join();
    e.join();
    f.join();
    g.join();
    h.join();
    i.join();
    j.join();
    k.join();
    l.join();
    m.join();
    n.join();
	return 0;
}


