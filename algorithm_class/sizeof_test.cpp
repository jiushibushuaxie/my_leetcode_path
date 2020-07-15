#include <iostream>

using namespace std;

int main()
{
    int a = 123;
    int *p = &a;
    cout<<sizeof(2.14)<<endl;  //double 8字节
    cout<<sizeof(2)<<endl;       //int 4字节
    cout<<sizeof('1')<<endl;    //char 1字节
    cout<<sizeof("1234")<<endl;   //char数组  5字节
    cout<<sizeof(p)<<endl;   //指针  指针在Win32下的大小为4字节 ， x64下的大小为8字节

    return 0;
}