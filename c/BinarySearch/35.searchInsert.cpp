/*
    35.搜索插入位置  
    难度：简单
    给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
    如果目标值不存在于数组中，返回它将会被按顺序插入的位置
    你可以假设数组中无重复元素。

示例 1:
    输入: [1,3,5,6], 5
    输出: 2
示例 2:
    输入: [1,3,5,6], 2
    输出: 1
*/

//解法
/*
    二分法
    特别注意边界条件
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

//方法一  视频课程中方法, 画个图，找个例子，易懂
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index = -1;
        int left = 0;
        int right = nums.size()-1;
        while(index == -1 ){     //未找到位置，进行循环
            int mid = left+ (right -left)/2;
            if(target == nums[mid]){
                index = mid;
            }
            else if(target<nums[mid]){
                if(mid==0||nums[mid-1]<target){                //再对边界条件及相邻元素进行判断
                    index = mid;
                }
                right = mid -1;
            }
            else if(nums[mid]<target){
                if(mid == nums.size()-1 ||target<nums[mid+1]){   //再对边界条件及相邻元素进行判断
                    index = mid+1;
                }
                left = mid +1;
            }
        }
        return index;
    }
};

//方法二,leetcode题解方法
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        // 因为有可能数组的最后一个元素的位置的下一个是我们要找的，故右边界是 len
        //插入的数用可能在末尾，因此right = length; 普通二分查找是right = length-1
        while(left<right){      //写成left<right 在退出循环时，总有left=right;
            int mid = left+(right - left)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target){     // nums[mid]<target时，排除法可知，要判断的区间肯定不在左区间
                left = mid+1;
            }
            else if(target<nums[mid]){
                right = mid;
            }
        }
        return left;  //返回left， 普通二分查找是返回-1，代表没查找到
    }
};