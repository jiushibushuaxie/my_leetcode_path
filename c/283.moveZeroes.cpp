/*
    283. 移动零
    难度:简单
    给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例
    输入: [0,1,0,3,12]
    输出: [1,3,12,0,0]

说明:
    必须在原数组上操作，不能拷贝额外的数组。
    尽量减少操作次数。

*/

/*
    解法一、
    解法二、从后往前，双指针
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

//解法一
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;
        //第一次遍历的时候，只要是非0的统统都赋给nums[j]
        for(int i=0;i<nums.size();++i){
            if(nums[i]!=0){
                nums[j] = nums[i];
                ++j;
            }
        }
        //第二次遍历把末尾的元素都赋为0即可
        for(;j<nums.size();++j){
            nums[j] = 0;
        }
    }
};

//这方法不是很好，存在重复移动
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = nums.size() -1;
        int right = nums.size() -1;
        
        while(left>=0){
            if(nums[left]==0){
                for(int i=left;i<right;++i){
                    swap(nums[i],nums[i+1]);
                }
                --right;
            }
            --left;
        }
    }
};