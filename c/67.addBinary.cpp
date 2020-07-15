/*
    67. 二进制求和
    难度:简单
    给你两个二进制字符串，返回它们的和（用二进制表示）。
    输入为 非空 字符串且只包含数字 1 和 0。

    字符串如果不是 "0" ，就都不含前导零。
示例:
    输入: a = "11", b = "1"
    输出: "100"
*/

/*
    解法：对每位字符上的加法，用数字操作。a[i] - '0' + b[j] - '0';
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int i = a.size()-1;
        int j = b.size()-1;
        int carry = 0;
        while(a[i]&&b[j]){
            int sum = a[i] - '0' + b[j] - '0'; 
            int push = (sum+carry)%2;
            ans += to_string(push);
            carry = sum/2;
            --i;
            --j;
        }
        while(a[i]){
            int sum = a[i] - '0' + carry; 
            int push = sum%2;
            ans += to_string(push);
            carry = sum/2;
            --i;
        }
        while(b[j]){
            int sum = b[i] - '0' + carry; 
            int push = sum%2;
            ans += to_string(push);
            carry = sum/2;
            --j;
        }
        if(carry){
            ans += to_string(carry);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
