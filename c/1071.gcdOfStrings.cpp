//问题描述
/*
    1071. 字符串的最大公因子
    对于字符串 S 和 T，只有在 S = T + ... + T（T 与自身连接 1 次或多次）时，我们才认定 “T 能除尽 S”。
    返回最长字符串 X，要求满足 X 能除尽 str1 且 X 能除尽 str2。

示例 1:
    输入：str1 = "ABCABC", str2 = "ABC"
    输出："ABC"
示例 2:
    输入：str1 = "ABABAB", str2 = "ABAB"
    输出："AB"
示例 3:
    输入：str1 = "LEET", str2 = "CODE"
    输出：""
*/


//解法
/*
    解法：枚举前缀，且前缀长度是两字符串长度的最大公约数
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int gcd(int a,int b){   //求最大公约数
        int r=b;
        while(a%b!=0){
            r = a%b;
            a = b ;
            b = r;
        }
        return b;
    }
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2 != str2+str1) return "";
        return str1.substr(0,gcd(str1.size(),str2.size())); 
        
    }
};

int main()
{
    Solution solver;
    string str1 = "ABCABC";
    string str2 = "ABC";
    int a = solver.gcd(str1.size(),str2.size());
    string res = solver.gcdOfStrings(str1,str2);
    cout<<a<<endl;
    cout<<res<<endl;
    
    return 0;
}
