//问题描述
/*
    26. 删除排序数组中的重复项  
    给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
    不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

示例 1:
    给定数组 nums = [1,1,2], 
    函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。 
    你不需要考虑数组中超出新长度后面的元素。

示例 2:
    给定 nums = [0,0,1,1,1,2,2,3,3,4],
    函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
    你不需要考虑数组中超出新长度后面的元素。
*/

//解法
/*
    双指针
    首先题目要求常数级别的空间复杂度，这个时候首先想到指针，使用双指针法可以解决这个问题。
    由于数组是有序的，所以我们用两个指针，第一个指针指向第一个元素，第二个指针指向第二个元素。
    用第二个指针遍历数组，如果发现第二个指针指向元素的值不等于第一个指针指向元素，
    这个时候将第一个指针向后移动一个元素，然后修改第一个指针指向的元素，直到for循环完成。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

//使用迭代器
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(!nums.size()) return 0;
        auto iter1 = nums.begin();
        auto iter2 = nums.begin() +1;
        for(iter2;iter2!=nums.end();iter2++){
            if(*iter1 != *iter2){
                ++iter1; 
                *iter1 = *iter2;
            }         
        }
        return iter1 - nums.begin() + 1;  
    }
};

//使用下标
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(!nums.size()) return 0;
        int i,j = 0;
        for(i=0;i!=nums.size();i++)
            if(nums[i]!=nums[j]){
                ++j;
                nums[j] = nums[i];
            }
        return j+1;
    }
};
