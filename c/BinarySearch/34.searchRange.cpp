/*
    34. 在排序数组中查找元素的第一个和最后一个位置  
    难度：中等

    给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
    你的算法时间复杂度必须是 O(log n) 级别。
    如果数组中不存在目标值，返回 [-1, -1]。

示例 1:
    输入: nums = [5,7,7,8,8,10], target = 8
    输出: [3,4]
示例 2:
    输入: nums = [5,7,7,8,8,10], target = 6
    输出: [-1,-1]
*/

//解法
/*
    二分法
    分别找出左右边界
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = left_bound(nums, target);
        int right = right_bound(nums, target);
        return {left,right};
    }

    int left_bound(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size()-1;
        while(left<=right){
            int mid = left + (right - left)/2;
            if(target == nums[mid]){
                if( mid==0 || nums[mid]>nums[mid-1]){   //边界条件，关键
                    return mid;
                }
                right= mid-1;          //关键 
            }
            else if(target<nums[mid]){
                right = mid-1;
            }
            else if(nums[mid]<target){
                left =  mid+1;
            }
        }
        return -1;
    }

    int right_bound(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size()-1;
        while(left<=right){
            int mid = left + (right - left)/2;
            if(target == nums[mid]){
                if( mid==nums.size()-1 || nums[mid]<nums[mid+1]){   //边界条件，关键
                    return mid;
                }
                left= mid+1;     //关键 
            }
            else if(target<nums[mid]){
                right = mid-1;
            }
            else if(nums[mid]<target){
                left =  mid+1;
            }
        }
        return -1;
    }
};