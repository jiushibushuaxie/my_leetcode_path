//问题描述
/*
    557.反转字符串中的单词 III 
    给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

示例 1:

    输入: "Let's take LeetCode contest"
    输出: "s'teL ekat edoCteeL tsetnoc" 

*/


//解法
/*
    解法一：自己写的哦，一次过~  可以使用栈，先进后出，空格为判断条件
    解法二：双指针在运行的过程中会有一个头指针固定，尾指针不断向前移动，
           遇到空格即为头指针和尾指针之间为一个单词，对这个单词进行反转即可。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;


class Solution {
public:
    string reverseWords(string s) {
        stack<char> str;
        string result;
        for(int i=0;i<s.size();++i){
            if(s[i]==' ') {
                while(!str.empty()){
                    result+=str.top();
                    str.pop();
                }
                result+=' ';
            }
            else str.push(s[i]);
        }
        while(!str.empty()){
            result+=str.top();
            str.pop();
        }
        return result;
    }
};

//双指针法
class Solution {
public:
    // 反转字符串  使用异或进行交换
    void reverseString(int front, int tail, string& str) {
        while (front < tail) {
            str[front] ^= str[tail];
            str[tail] ^= str[front];
            str[front++] ^= str[tail--];
        }
    }
    // 确定单词边界
    string reverseWords(string s) {
        int front = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                reverseString(front, i - 1, s);
                front = i + 1;
            }
        }
        reverseString(front, s.length() - 1, s);
        return s;
    }
};
