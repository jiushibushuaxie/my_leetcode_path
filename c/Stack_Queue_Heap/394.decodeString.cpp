/*
    394. 字符串解码
    难度:中等
    给定一个经过编码的字符串，返回它解码后的字符串。
    编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
    你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
    此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。

示例 1：
    输入：s = "3[a]2[bc]"
    输出："aaabcbc"

示例 2：
    输入：s = "3[a2[c]]"
    输出："accaccacc"

示例 3：
    输入：s = "2[abc]3[cd]ef"
    输出："abcabccdcdcdef"

示例 4：
    输入：s = "abc3[cd]xyz"
    输出："abccdcdcdxyz"
*/

//解法
/*
    用两个栈，一个存重复次数，一个存对应的重复字符串
    逻辑性很强，需要好好分析
    注意最后返回的是str
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        int num = 0;
        stack<string> strs;
        string str = "";
        for(int i=0;i<s.size();++i){
            if(s[i]>='0'&&s[i]<='9'){
                num = num*10+ s[i]-'0';
            }
            else if((s[i] >= 'a' && s[i] <= 'z') ||(s[i] >= 'A' && s[i] <= 'Z')){
                str +=s[i];
            }
            else if(s[i]=='['){  //遇到'['，将‘[’前的数字压入nums栈内，字母字符串压入strs栈内
                nums.push(num);
                num = 0;
                strs.push(str);
                str = "";
            }   
            else if(s[i]==']'){ //遇到'[',出栈
                int times = nums.top();
                nums.pop();
                for(int j=0;j<times;++j){
                    strs.top() += str;  
                }
                str = strs.top();   //之后若还是字母，就会直接加到str之后，因为它们是同一级的运算
                                    //若是左括号，str会被压入strs栈，作为上一层的运算
                strs.pop();
            }
        }
        return str;
    }
};