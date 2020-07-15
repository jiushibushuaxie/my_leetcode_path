/*
    22. 括号生成
    难度:中等
    数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

示例：
    输入：n = 3
    输出：[
        "((()))",
        "(()())",
        "(())()",
        "()(())",
        "()()()"
        ]
*/

/*
    解法：递归
    1、左右括号的数量最多为n个；
    2、若左括号的数量<=右括号数量时，不可进行放置右括号的递归
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate("", n, n, result);   //左右括号最多可以放置n个
        return result;
    }

private:
    void generate(string item, int left, int right, vector<string>& result){
        //left当前可以放置左括号的数量， right当前可以放置右括号的数量
        if(left==0&&right == 0){
            result.push_back(item);
            return;
        }
        if(left>0){              //什么情况放置左括号，当还有左括号可以放置时
            generate(item+ "(", left-1, right, result);
        }
        if(left<right){          //什么情况放置右括号，当剩余左括号<剩余右括号时
            generate(item+ ")", left, right-1, result);
        }
    }
};