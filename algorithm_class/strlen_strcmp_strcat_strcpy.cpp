#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>
#include <cstring> 

using namespace std;

int my_strlen(const char *str){
    assert(str!=nullptr);
    int length = 0;
    while(*str!='\0'){
        str++;
        length++;
    }
    return length;
}

//字符串比较  strcmp将两个字符串从左先右逐个字符比较其ASCII值得大小，直到出现不同的字符或遇到'\0'为止
int my_strcmp(const char *str1,const char *str2){
    assert(str1!=nullptr && str2!=nullptr);
    int flag = 0;
    //s1 ="abcde"; s2 = "abcdee"; 则flag = '\0'-'e' < 0    因为'\0'减去任何字符都小于0
    //一定要讲char* 转换为unsigned char*     && *str1不能省，要考虑相等时，比较到最后'\0'的情况
    while(!(flag=*(unsigned char*)str1-*(unsigned char*)str2) && *str1){
        str1++;
        str2++;
    }
    if(flag>0)
		return 1;
	else if(flag<0)
		return -1;
	else
		return 0;
}


//strcat(dest,src)把src所指字符串调教到dest结尾处（覆盖dest结尾的'\0'），并添加'\0'
char *my_strcat(char *dest,const char *src){
    assert(dest!=nullptr && src!=nullptr);
    char *result = dest;  //用于保存dest的初始值头指针，用于返回
    while(*dest!='\0'){
        dest++;
    }
    // while(*src!='\0'){
    //     *dest = *src;
    //     src++;
    //     dest++;
    // }
    // *dest = '\0';
    //或是
    while(*dest++=*src++);
    return result;

}

//strcpy(dest,src) 把从src开始的含有Null结束符的字符串复制到以dest开始的地址空间 
char *my_strcpy(char *dest,const char *src){
    assert(dest!=nullptr && src!=nullptr);
	char *result=dest;
    //attention此处，若*src为’\0‘，则其先赋值给dest，故最后不需要再添加'\0'
	while(*dest++=*src++);
	return result;
}


int main()
{
    char str1[] = "abcde";
    char str2[] = "abcdee";
    int flag = 0;
    char s1 = '\0';
    char s2 = 'e';
    flag=(unsigned char)s1-(unsigned char)s2;
    cout<<"str1_length "<<my_strlen(str1)<<endl;
    cout<<"str2_length "<<my_strlen(str2)<<endl;
    cout<<"str_compare "<<my_strcmp(str1, str2)<<endl;
    cout<<"str_cat "<<my_strcat(str1, str2)<<endl;
    cout<<"str_cpy "<<my_strcpy(str1, str2)<<endl;
    return 0;
}
