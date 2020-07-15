//问题描述
/*
    14. 最长公共前缀  
    编写一个函数来查找字符串数组中的最长公共前缀。  
    如果不存在公共前缀，返回空字符串 ""。

示例 1:
    输入: ["flower","flow","flight"]
    输出: "fl"

示例 2:

    输入: ["dog","racecar","car"]
    输出: ""
    解释: 输入不存在公共前缀。

*/

//解法
/*
  3个字符串的最长公共前缀一定被包含在前2个字符串的最长公共前缀之中，
  同理，N个字符串的前缀一定是其中（N-1）个字符串的最长公共前缀与第N个字符串的最长公共前缀
  substr(pos, n) 两个参数，起始位置，长度
*/
#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        auto v_n = strs.size();
        if(!v_n) return "";  //空的容器时
        sort(strs.begin(), strs.end());  //排序一遍后，只需要比较最大最小两个str即可
        string result = "";
        int length = min(strs[0].size(),strs[v_n-1].size());
        for(int i=0; i!=length; ++i){
            if(strs[0][i] != strs[v_n-1][i])
                return strs[0].substr(0,i);
        }
        return strs[0].length() > strs[v_n-1].length()? strs[v_n-1]:strs[0];  //若是子串，一定要比较第一个字符串和最后字符串的位数
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int v_n = strs.size();
        if(!v_n) return "";  //空的容器时
        string common_str = strs[0];  //把共有前缀设为第一个字符串，然后不断减小字符串位数
        for(string str:strs){
            while(str.substr(0,common_str.size())!= common_str){
                common_str = common_str.substr(0, common_str.size()-1);
            }
        }
        return common_str;
    }
};