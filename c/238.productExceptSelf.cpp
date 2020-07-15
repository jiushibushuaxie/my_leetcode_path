/*
    238. 除自身以外数组的乘积
    难度：中等
    给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，
    其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。
示例:
    输入: [1,2,3,4]
    输出: [24,12,8,6]
*/

/*
   在 O(n) 时间复杂度内完成此题。
   乘积 = 当前数左边的乘积 * 当前数右边的乘积
   构造两个数组
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        vector<int> left(nums.size(),0);
        vector<int> right(nums.size(),0);
        left[0] = 1;
        right[nums.size()-1] = 1;

        for(int i=1;i<nums.size();++i){
            left[i] = left[i-1]*nums[i-1];
        }
        for(int i=nums.size()-2;i>=0;--i){
            right[i] = right[i+1]*nums[i+1];
        }
        for(int i=0;i<nums.size();++i){
            ans[i] = left[i]*right[i];
        }
        return ans;
    }
};