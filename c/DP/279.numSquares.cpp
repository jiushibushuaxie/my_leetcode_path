/*
    279.完全平方数
    难度：中等
    给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。
    你需要让组成和的完全平方数的个数最少。

示例 1:
    输入: n = 12
    输出: 3 
    解释: 12 = 4 + 4 + 4.

    输入: n = 13
    输出: 2
    解释: 13 = 4 + 9.
*/

//解法
/*
    四平方定理： 任何一个正整数都可以表示成不超过四个整数的平方之和。因此答案只可能是1,2,3,4
    dp
    1、子问题dp[i][j]:  整数i对应的最小平方组成个数
    2、边界条件dp[0] = 0;
    3、状态转移方程 dp[i] = min(dp[i - j*j]);  其中j*j<i 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 0);//n+1大小，dp[0]为0
		for (int i = 1; i <= n; i++) {//从dp[1]开始计算
			int minVal = 4;  //四平方定理
			for ( int j = 1; j*j <= i ; j++ )  {
                minVal = min(minVal, dp[i - j*j]);
            }
			dp[i] = minVal + 1;
		}
		return dp[n];
    }
};