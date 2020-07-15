/*
    33. 搜索旋转排序数组 
    难度：中等

    假设按照升序排序的数组在预先未知的某个点上进行了旋转。

    ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

    搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

    你可以假设数组中不存在重复的元素。

    你的算法时间复杂度必须是 O(log n) 级别。

示例 1:
    输入: nums = [4,5,6,7,0,1,2], target = 0
    输出: 4

示例 2:
    输入: nums = [4,5,6,7,0,1,2], target = 3
    输出: -1
*/

//解法
/*
    二分法
    较难
    旋转数组一定有一个性质： nums[0]>nums[nums.size()-1] 首元素大于末尾元素
    因此： 将数组首元素 与nums[mid]做比较  来确定二分区间
    因此有很多种情况，一是比较target与nums[mid]  二是比较nums[left]与nums[mid] 
                   三是比较nums[left]与target(用于确定旋转区间)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(left<=right){
            int mid = left + (right - left)/2;
            if(target==nums[mid]){
                return mid;
            }
            else if (target<nums[mid]){         //第一层
                if(nums[left]<nums[mid]){         //第二层
                    if(nums[left]<=target){           //第三层
                        right = mid-1;
                    }
                    else if(nums[left]>target){
                        left = mid+1;
                    }
                }
                else if (nums[left]>nums[mid]){     //第二层
                    right = mid -1;
                }
                else if(nums[left]==nums[mid]){     //第二层
                    left = mid+1;
                }
            }
            else if (target>nums[mid]){             //第一层
                if(nums[left]<nums[mid]){            //第二层
                    left = mid +1;
                }
                else if (nums[left]>nums[mid]){     //第二层
                    if(nums[left]<=target){         //第三层
                        right = mid -1;
                    }
                    else {
                        left = mid +1;
                    }
                }
                else if(nums[left]==nums[mid]){     //第二层
                    left = mid+1;
                }
            }
        }
        return -1;
    }
};