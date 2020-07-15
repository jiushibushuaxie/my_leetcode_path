/*

*/
//方法一
//联合体union的存放顺序是所有成员都从低地址开始存放，
//利用该特性就可以轻松地获得了CPU对内存采用Little-endian还是Big-endian模式读写。
/*return 1: little-endian, return 0: big-endian*/
int checkCPUendian(){
    union{
        unsigned int a;
        unsigned char b; 
    }c;
    c.a = 1;
    if(c.b == 1){
        return 1;   //小段
    }

    return 0;   //大端
}

//方法二
#include <cstdio>

void checkCPUendian_2(){
    int i = 1;   
    char *p = (char *)&i;       //int* 转为 char* 因为char只占一个字节
    if(*p == 1)     
        printf("Little Endian"); 
    else
        printf("Big Endian");
}
    