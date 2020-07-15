//实现一个 Memcpy 函数
//要考虑源和目标内存重叠的情况

#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>
#include <cstring> 
using namespace std;

//将由src指向地址为起始地址的连续n个字节的数据复制到以dest指向地址为起始地址的空间内，函数返回一个指向dest的指针
//单字节拷贝
void * mymemcpy(void *dest, const void *src, size_t n)
{
    if (dest == NULL || src == NULL)
          return NULL;

    char *pdest = (char*)dest;                    //类型转换
    const char *psrc  = (const char*)psrc;         //类型转换

    if (pdest > psrc && pdest < psrc+n)  //有内存重叠，dst在src和src+size之间，高位到低位复制  
    {
        pdest = pdest + n - 1;
        psrc = psrc + n - 1;
        while (n--)
            *pdest-- = *psrc--;
    }
    else
    {
        while(n--)       ////没有内存重叠或src在dst和dst+size之间，低位到高位复制  
            *pdest++ = *psrc++;
    }
    
    return dest;
}


//4字节拷贝
void *my_memcpy(void *dst, const void *src, int n){
    if (dst == NULL || src == NULL || n <= 0)
        return NULL;

    int * pdst = (int *)dst;
    int * psrc = (int *)src;
    char *tmp1 = NULL;
    char *tmp2 = NULL;
    int c1 = n / 4;    
    int c2 = n % 4;

    if (pdst > psrc && pdst < psrc + n){  //有内存重叠，dst在src和src+size之间，高位到低位复制 
        tmp1 = (char *)pdst + n - 1;
        tmp2 = (char *)psrc + n - 1;
        while(c2--)
            *tmp1-- = *tmp2--;
        pdst = (int *)tmp1;
        psrc = (int *)tmp2;
		while (c1--)
            *pdst-- = *psrc--;
    }
    else{
        while (c1--)
            *pdst++ = *psrc++;
        tmp1 = (char *)pdst;
		tmp2 = (char *)psrc;
        while (c2--)
            *tmp1++ = *tmp2++;
    }
    return dst;
}
