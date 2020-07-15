//问题描述
/*
    38. 外观数列  
  「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。前五项如下：

1.     1
2.     11
3.     21
4.     1211
5.     111221

1 被读作  "one 1"  ("一个一") , 即 11。
11 被读作 "two 1s" ("两个一"）, 即 21。
21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。

    
示例 1:

    输入: 1
    输出: "1"
    解释：这是一个基本样例。

示例 2:

    输入: 4
    输出: "1211"
    解释：当 n = 3 时，序列是 "21"，其中我们有 "2" 和 "1" 两组，"2" 可以读作 "12"，也就是出现频次 = 1 而 值 = 2；类似 "1" 可以读作 "11"。所以答案是 "12" 和 "11" 组合在一起，也就是 "1211"。
*/


//解法
/*
    递归
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string countAndSayCore(string s) {
        string result="";
        int count =1;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1]) count++;
            else{
                result+=(to_string(count)+s[i]);
                count=1;
            } 
        }
        //此处要加上最后一个子序列的描述
        result+=(to_string(count)+s[s.size()-1]);  
        return result;
    }

    string countAndSay(int n) {
        string res = "1";
        for(int i=0;i<n-1;i++){
            res = countAndSayCore(res);
        }
        return res;
    }
};