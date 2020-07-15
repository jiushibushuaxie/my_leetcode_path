/*
    152. 乘积最大子数组
    难度：中等
    给你一个整数数组 nums ，
    请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

示例1: 
    输入: [2,3,-2,4]
    输出: 6
    解释: 子数组 [2,3] 有最大乘积 6。
示例2: 
    输入: [-2,0,-1]
    输出: 0
    解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
*/

/*
    动态规划
    1、子问题   以下标i结尾的最大子数组乘积，以及最小数组乘积
    2、边界条件 d当负数出现时则imax与imin进行交换再进行下一步计算
    3、状态转移方程   
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
    int maxProduct(vector<int>& nums) {
        int imax = 1;
        int imin = 1;
        int ans = INT_MIN;
        for(int i=0;i<nums.size();++i){
            if(nums[i]<0){
                swap(imax,imin);
            }
            imax = max(imax*nums[i],nums[i]);
            imin = min(imin*nums[i],nums[i]);   //如果nums[i]=0，imax,imin都为0，重新开始计算
            ans =  max(ans,imax);               //但ans已经记录下nums[i]=0 前面的最大值
        }
        return ans;
    }
};