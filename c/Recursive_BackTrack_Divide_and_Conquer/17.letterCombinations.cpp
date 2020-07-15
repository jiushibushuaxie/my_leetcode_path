/*
    17. 电话号码的字母组合
    难度：中等
    给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
    给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

示例:
    输入："23"
    输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

*/

//解法
/*
    求所有组合，回溯
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(!digits.size()) return {};
        vector<string> ans;
        string item = "";
        vector<string> table = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        back_track(0,digits,ans,item,table);  
        return ans;
    }
    void back_track(int i,string& digits,vector<string>& ans,
                    string& item, vector<string>& table){
        if(i==digits.size()){           //递归结束条件。
            return;
        }
        int num = digits[i] - '0';
        for(int j=0;j<table[num-2].size();++j){         //这个for循环很重要，用于遍历不同数字可以取的字符
            item += table[num-2][j];
            if(item.size()==digits.size()){
                ans.push_back(item);
            }
            back_track(i+1,digits,ans,item,table);      //递归，对i进行递归
            item.pop_back();                            //回溯,对item进行回溯
        }
    }
};