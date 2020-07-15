//问题描述
/*
    局部字符串反转函数，非常有用
    使用string.h中的strrev函数      strrev(s);
    现有的函数 使用algorithm中的reverse函数         reverse(s.begin(),s.end());  

*/
#include<iostream>
#include<vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>

using namespace std;

string reverse_str(string str){
    int length = str.size();
    for(int i=0;i<length/2;i++)
    {
        char temp = str[i];
        str[i] = str[length-1-i];
        str[length-1-i] = temp;
    }
    return str;
}

string reverse_string(string str){
        string result = str;
        int i =0;
        while(i<str.size()/2){
            swap(result[i],result[result.size()-1-i]);
            i++;
        }
        return result;
    }

int main()
{
    string str ="qwert" ;
    string result = reverse_str(str);
    string result2 = reverse_string(str);
    cout<<result<<endl;
    cout<<result2<<endl;
    return 0;
}
