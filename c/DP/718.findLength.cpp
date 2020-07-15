/*
    718. 最长重复子数组
    难度：中等

    给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。

示例：
    输入：
    A: [1,2,3,2,1]
    B: [3,2,1,4,7]
    输出：3
    解释：
    长度最长的公共子数组是 [3, 2, 1] 。
*/

//解法
/*
    两个数组一般都是DP方法，两个字符串也是
    类似于LCS
    动态规划
    1、子问题 dp[i][j]代表以A[i-1]与B[j-1]结尾的公共字串的长度,公共字串必须以A[i-1]，B[j-1]结束
    2、边界条件  i-1>=0,j-1>=0
    3、状态转移方程 dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];

    注意子数组和子序列的区别    子序列默认不连续，子数组默认连续
    如果是子序列的话 递推公式就是：dp[i][j] = max(dp[i-1][j-1]+(A[i-1] == B[j-1]?1:0),dp[i-1][j],dp[i][j-1])
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
    int findLength(vector<int>& A, vector<int>& B) {
        vector<vector<int> > dp(A.size()+1, vector<int>(B.size()+1,0));
        int ans = 0;
        for(int i=1;i<A.size()+1;++i){
            for(int j=1;j<B.size()+1;++j){
                if(A[i-1]==B[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                ans = max(ans,dp[i][j]);
            }
        }   
        return ans; 
    }
};