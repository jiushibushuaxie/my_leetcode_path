/*
    416. 分割等和子集
    难度：中等
    给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

示例:
    输入: [1, 5, 11, 5]
    输出: true
    解释: 数组可以分割成 [1, 5, 5] 和 [11].：

    输入: [1, 2, 3, 5]
    输出: false
    解释: 数组不能分割成两个元素和相等的子集.
*/


//解法
/*
    可以转化为01背包问题
    dp[i][j] 对于nums[i]，背包容量为j
    边界条件： dp[i][0] = true  因为背包没有空间的时候，就相当于装满了
    状态方程： 装入或不装入背包 dp[i][j] = dp[i - 1][j] | dp[i - 1][j-nums[i-1]]
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums) {
            sum += num;
        }
        if(sum%2 == 1) {
            return false;
        }
        sum = sum/2;
        vector<vector<bool>> dp(nums.size()+1,vector<bool>(sum+1,false));

        //边界条件
        dp[0][0] = true;
        
        for(int i=1;i<=nums.size();i++){    //注意i起始为1，因为下面需要判断nums[i-1],dp[i-1][j]
            for(int j = 0;j<=sum;++j){      //这里j一定要从0开始
                if(nums[i-1]>j){
                    // 背包容量不足，不能装入第 i 个物品
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j] | dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[nums.size()][sum];
    }
};

//空间优化
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums) {
            sum += num;
        }
        if(sum%2 == 1) {
            return false;
        }
        sum = sum/2;
        vector<bool> dp(sum+1,false);
        dp[0] = true;       //边界条件

        for(int i=1;i<=nums.size();i++){    
            for(int j = sum;j>=0;--j){      //注意这里是逆序
                if (j - nums[i-1] >= 0) {
                    dp[j] = dp[j] | dp[j-nums[i-1]];
                }
                // else{
                //     continue;  //j - nums[i] < 0时，背包空间不够，不用操作，状态不变
                // }
            }
        }
        return dp[sum];
    }
};