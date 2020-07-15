/*
    438. 找到字符串中所有字母异位词
    难度：中等
    给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。
    字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。


    返回可以使最终数组和为目标数 S 的所有添加符号的方法数。
示例:
   输入:
    s: "abab" p: "ab"

    输出:
    [0, 1, 2]

    解释:
    起始索引等于 0 的子串是 "ab", 它是 "ab" 的字母异位词。
    起始索引等于 1 的子串是 "ba", 它是 "ab" 的字母异位词。
    起始索引等于 2 的子串是 "ab", 它是 "ab" 的字母异位词。

*/

//解法
/*
    双指针，滑动窗口
    两个数组needs和window来分别记录需要得到的元素和滑动窗口遍历到的元素
    如果window数组中记录的元素个数超过了needs数组的元素个数，则开始移动左窗口慢慢减少多余的个数
    当right-left==p.size()，肯定满足条件（因为窗口不存在多余的字符）
    窗口若包含needs中没有的字符呢? needs数组中已经初始化为0，若包含，则不断移动left至当前位置
    needs数组整个过程不变
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> window(26, 0);
        vector<int> needs(26, 0);
        
        int left = 0,right =0;
        for(int i=0;i<p.size();++i){
            ++needs[p[i]-'a']; 
        }
        while(right<s.size()){
            //计数
            char curR = s[right];
            right++;
            // 将右窗口当前访问到的元素 curR 个数加 1 
            ++window[curR - 'a'];

            // 当 window 数组中 curR 比 needs 数组中对应元素的个数要多的时候就该移动左窗口指针 
            while (window[curR-'a'] > needs[curR-'a']) {
                char curL = s[left];
                left++;
                // 将左窗口当前访问到的元素 curL 个数减 1 
                --window[curL-'a'];            
            }
            
            if(right-left==p.size()){
                ans.push_back(left);
            }
        }
        return ans;
    }
};
