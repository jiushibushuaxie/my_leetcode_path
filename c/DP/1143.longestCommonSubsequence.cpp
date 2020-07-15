/*
    1143. 最长公共子序列
    难度：中等
    给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度。

    一个字符串的 子序列 是指这样一个新的字符串：
    它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
    例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
    两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列。

    若这两个字符串没有公共子序列，则返回 0。

示例：
    输入：text1 = "abcde", text2 = "ace" 
    输出：3  
    解释：最长公共子序列是 "ace"，它的长度为 3。
示例
    输入：text1 = "abc", text2 = "abc"
    输出：3
    解释：最长公共子序列是 "abc"，它的长度为 3。

*/

/*
    动态规划
    1、子问题dp[i][j]：text1前i个元素（下标为i-1） 与 text2前j个元素（下标为j-1） 的最长公共子序列长度 
    2、边界条件 dp[0][0]等于0，等于dp数组总体往后挪了一个，免去了判断出界
    3、状态转移方程 
        if(text1[i-1]==text2[j-1])  那么 dp[i][j] = dp[i-1][j-1] + 1
        if text1[i-1]！=text2[j-1]   那么 dp[i][j] = max(dp[i-1][j]，dp[i][j-1]);

    注意子数组和子序列的区别    子序列默认不连续，子数组默认连续
    
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
    int longestCommonSubsequence(string text1, string text2) {
        int ans;
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));
        for(int i=1;i<text1.size()+1;++i){
            for(int j=1;j<text2.size()+1;++j){
                if(text1[i-1]==text2[j-1]){     //注意这里是text1[i-1]==text2[j-1]
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];   
    }
};
