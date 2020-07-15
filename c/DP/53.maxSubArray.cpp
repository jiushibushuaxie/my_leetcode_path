//问题描述
/*
    53.最大子序和  
    给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例 1:
    输入: [-2,1,-3,4,-1,2,1,-5,4],
    输出: 6
    解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

进阶:
    如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
*/

//解法
/*
    //最大和连续子数组 一定包含  最大数组元素
    以最大数组元素两边展开，跟暴力法差不多

    //动态规划
    i位置下最大连续子序列和为sum[i]，因为sum[i-1]是否大于0
    则   sum[i] = max( sum[i-1]+nums[i],  nums[i])
    上述状态转移方程得知，获得下一个状态时只需要知道上一个状态就好，所以我们完全可以用一个变量表示状态，而不是用一个数组。

    //贪心法

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

//暴力法 O(n^2)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        auto n = nums.size();
        if(!n) return 0;
        if(n==1) return nums[0];
        int i,j;
        int sum = 0;
        int result = INT_MIN;
        for(i=0;i!=n;i++){
            for(j=i;j!=n;j++){
                sum += nums[j];
                result = sum>result?sum:result;
            }
            sum = 0;
        }
        return result;
    }
};

// 动态规划  O(n)时间复杂度  O(n)空间复杂度
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        auto n = nums.size();
        if(!n) return 0;
        if(n==1) return nums[0];
        vector<int> sum(n);
        int result = nums[0];
        sum[0] = nums[0];
        
        for(int i=1;i!=n;i++){
            int temp = sum[i-1] + nums[i];
            sum[i] = temp>nums[i]?temp:nums[i];
            result = sum[i]>result?sum[i]:result;
        }
        return result;
    }
};

//贪心法
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        //类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
        int result = INT_MIN;
        int numsSize = int(nums.size());
        int sum = 0;
        for (int i = 0; i < numsSize; i++)
        {
            sum += nums[i];
            result = max(result, sum);
            //如果sum < 0，重新开始找子序串
            if (sum < 0){
                sum = 0;
            }
        }

        return result;
    }
};
