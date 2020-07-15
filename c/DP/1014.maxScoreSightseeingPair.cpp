/*
    1014. 最佳观光组合
    难度:中等
    给定正整数数组 A，A[i] 表示第 i 个观光景点的评分，并且两个景点 i 和 j 之间的距离为 j - i。
    一对景点（i < j）组成的观光组合的得分为（A[i] + A[j] + i - j）：景点的评分之和减去它们两者之间的距离。
    返回一对观光景点能取得的最高分。
示例:
    输入：[8,1,5,2,6]
    输出：11
    解释：i = 0, j = 2, A[i] + A[j] + i - j = 8 + 5 + 0 - 2 = 11
*/

/*
    解法：动态规划 
    1、dp[i]代表  前i个观光景点能取得的最高分。
    2、边界条件  dp[0] = A[i], 同时记录评分最高景点的index, max_index的更新要注意值差与下标差
    3、状态转移方程  dp[i] = max(dp[i-1], A[i]+A[max_index]+index - i);  
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        vector<int> dp(A.size(),0);
        int max_index = 0;
        dp[0] = A[0];
        for(int i=1;i<A.size();++i){
            dp[i] = max(dp[i-1], A[i]+A[max_index]+max_index - i);
            if(A[i]>=A[max_index]){
                max_index = i;
            }
            else if(A[i]<A[max_index]){
                if((A[max_index]-A[i])<=(i-max_index-1)){
                    max_index = i;
                }
            }
        }
        return dp[A.size()-1];
    }
};