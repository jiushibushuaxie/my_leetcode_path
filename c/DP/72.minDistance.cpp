/*
    72. 编辑距离
    难度：困难
    给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。
    你可以对一个单词进行如下三种操作：

    插入一个字符
    删除一个字符
    替换一个字符

示例1:
    输入：word1 = "horse", word2 = "ros"
    输出：3
    解释：
    horse -> rorse (将 'h' 替换为 'r')
    rorse -> rose (删除 'r')
    rose -> ros (删除 'e')
*/

//解法
/*
    dp
    1、子问题  dp[i][j] word1第i个字符，word2第j个字符时的操作数 
    2、边界条件  dp[i][0] =i,代表j走完后，i还剩的操作步数。 dp[0][j] = j;同理
    3、状态转移方程 dp[i][j] =1 +  min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));

        //边界条件
        for(int i=0;i<=len1;++i){
            dp[i][0] = i;
        }
        for(int j=0;j<=len2;++j){
            dp[0][j] = j;
        }

        for(int i=1;i<=len1;++i){
            for(int j=1;j<=len2;++j){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] =1 + min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                }
            }
        }
        return dp[len1][len2];
    }
};