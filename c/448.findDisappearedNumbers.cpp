/*
    448. 找到所有数组中消失的数字
    难度:简单
    给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。
    找到所有在 [1, n] 范围之间没有出现在数组中的数字。

    不使用额外空间,时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。

示例
    输入:
    [4,3,2,7,8,2,3,1]

    输出:
    [5,6]
*/

/*
    要求时间复杂度为O(n)，不使用额外空间
    排序比较肯定不行，超出时间复杂度

    将所有正数作为数组下标，置对应数组值为负值。那么，仍为正数的位置即为（未出现过）消失的数字。
    实际上相当于利用正负号构建了一个简易的哈希表,用来存储每个数字的状态.实在是太巧妙啦! 
    原始数组：[4,3,2,7,8,2,3,1]
    重置后为：[-4,-3,-2,-7,8,2,-3,-1]
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
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();++i){         
            int index = abs(nums[i])-1;     //-1是因为元素数值从1开始
            if(nums[index]>0){
                nums[index] = - nums[index];
            }
        }
        for(int i=0;i<nums.size();++i){
            if(nums[i]>0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};