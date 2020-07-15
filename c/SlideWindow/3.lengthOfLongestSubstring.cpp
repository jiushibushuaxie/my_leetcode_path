//问题描述
/*
    3.无重复字符的最长子串
    难度：中等
    给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

    输入: "abcabcbb"
    输出: 3 
    解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。


示例 2:

    输入: "bbbbb"
    输出: 1
    解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:
    输入: "pwwkew"
    输出: 3
    解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
        请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。


说明:
    输出结果中的每个元素一定是唯一的。
    我们可以不考虑输出结果的顺序。
*/

//解法
/*
   滑动窗口
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

//滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        if(!len) return 0;
        if(len == 1) return 1;
        int start =0;
        int end = 1;
        int tmp_len = 0;
        int maxlen = 1;
        string cur_str = "";
        while(end<len){
            //判断末尾字符在之前出现过没有
            for(int i=start;i<end;i++){  
                if(s[i]==s[end]){       //s[end]出现过就滑动窗口
                    start = i+1;        //保证start-end区间内没有重复字符
                    break;
                }
            }  
            tmp_len = end-start+1;      //记录窗口大小
            maxlen = max(maxlen,tmp_len);
            end ++;
        }
        return maxlen;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string test = "auedr";
    int ans = s.lengthOfLongestSubstring(test);
    cout<<ans<<endl;
    return 0;
}
