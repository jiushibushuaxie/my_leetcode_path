/*
    209. 长度最小的子数组
    难度：中等
    给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组，并返回其长度。
    如果不存在符合条件的连续子数组，返回 0。

示例: 
    输入: s = 7, nums = [2,3,1,2,4,3]
    输出: 2
    解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。

*/

/*
    双指针 时间复杂度o(n) 空间复杂度O(1)
    需要满足两个条件 （1）和 ≥ s  （2）长度最小。  两者存在矛盾，故用双指针滑动窗口
    当窗口内（start ~ end）元素之和sum 大于 s时， ++start，直至sum<s, 过程中不断记录最小长度。
    当sum<s时，end++
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
    int minSubArrayLen(int s, vector<int>& nums) {
        int start = 0; 
        int end = 0;
        int sum = 0;
        int ans = INT_MAX;
        while(end<nums.size()){
            sum+=nums[end];
            while(sum>=s&&start<=end){
                ans = min(ans, end-start+1);
                sum -= nums[start];
                ++start;
            }
            ++end;
        }
        return (ans == INT_MAX) ? 0: ans;
    }
};
