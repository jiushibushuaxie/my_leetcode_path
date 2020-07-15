//问题描述
/*
    20. 有效的括号  
    给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
    有效字符串需满足：

    左括号必须用相同类型的右括号闭合。
    左括号必须以正确的顺序闭合。

    注意空字符串可被认为是有效字符串。
示例 1:

    输入: "()"
    输出: true

示例 2:

    输入: "()[]{}"
    输出: true

示例 3:

    输入: "(]"
    输出: false

示例 4:

    输入: "([)]"
    输出: false

示例 5:

    输入: "{[]}"
    输出: true
*/

//解法
/*
  大话数据结构上说过，用栈来做
  需要熟悉栈的结构怎么用代码来写
  C++有stack标准库类型
  stack的定义：stack<typename> name;
    压栈：name.push(i);
    出栈：name.pop();因为出栈是弹出栈顶元素，所以无需传入参数
    获取栈顶元素：name.top();
    判断栈是否为空：name.empty();如果为空返回true，否则返回false

*/
#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> linkstack;
        auto n = s.size(); 
        if(!n) return true;
        for(char c:s){
            if(linkstack.empty())    //保证链表在for循环中不为空
                linkstack.push(c);
            else if(c-linkstack.top()==1 || c-linkstack.top()==2)
                linkstack.pop();
            else
                linkstack.push(c);
        }
        return linkstack.empty();
    }
};