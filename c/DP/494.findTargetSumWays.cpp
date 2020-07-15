/*
    494. 目标和
    难度：中等
    给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。
    现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。

    返回可以使最终数组和为目标数 S 的所有添加符号的方法数。
示例:
    输入：nums: [1, 1, 1, 1, 1], S: 3
    输出：5
    解释：

    -1+1+1+1+1 = 3
    +1-1+1+1+1 = 3
    +1+1-1+1+1 = 3
    +1+1+1-1+1 = 3
    +1+1+1+1-1 = 3

    一共有5种方法让最终目标和为3。
*/

//解法
/*
    感觉可以转化为01背包问题
    sum(P) 前面符号为+的集合；sum(N) 前面符号为减号的集合
    所以题目可以转化为
     * sum(P) - sum(N) = target
     * sum(nums) + sum(P) - sum(N) = target + sum(nums)
    即 * sum(P) = (target + sum(nums)) / 2
    因此题目转化为01背包，sum(P)代表价值
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        long sum = 0;
        for (int it : nums) sum += it;
        if ((S + sum) % 2 == 1 || S > sum) return 0;    
        int jsize = (S+sum)/2 ;
        vector<vector<int>> dp(nums.size()+1,vector<int>(jsize+ 1,0));

        //边界条件
        dp[0][0] = 1;       //和为0的选择为1
        
        for(int i=1;i<=nums.size();++i){
            for(int j=0;j<=jsize;++j){
                if(j-nums[i-1] < 0) {        //背包容量不足，不能放入第i个物品
                    dp[i][j] = dp[i-1][j];  
                }
                else{
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];   //装入第i个物品或者不装入
                }
            }
        }
        return dp[nums.size()][jsize];
    }
};

//dfs,回溯，二叉树前序遍历
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return dfs(nums, S, 0);
    }

    int dfs(vector<int> &nums, int target, int left) {
        if (target == 0 && left == nums.size()) return 1;
        if (left >= nums.size()) return 0;
        int ans = 0;
        ans += dfs(nums, target - nums[left], left + 1);
        ans += dfs(nums, target + nums[left], left + 1);
        return ans;
    }
};

//空间优化dp
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        long sum = 0;
        for (int it : nums) sum += it;
        if ((S + sum) % 2 == 1 || S > sum) return 0;    
        int jsize = (S+sum)/2 ;
        vector<int> dp(jsize+1,0);

        //边界条件
        dp[0] = 1;       //和为0的选择为1
        
        for(int i=1;i<=nums.size();++i){
            for(int j=jsize;j>=0;--j){
                if(j-nums[i-1] >= 0) {       
                    dp[j] = dp[j] + dp[j-nums[i-1]];   //装入第i个物品或者不装入
                }
            }
        }
        return dp[jsize];
    }
};
