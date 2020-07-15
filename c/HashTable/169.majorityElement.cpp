//问题描述   
/*
    169. 多数元素
    给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
    你可以假设数组是非空的，并且给定的数组总是存在多数元素。

示例 1:

    输入: [3,2,3]
    输出: 3

示例 2:
    输入: [2,2,1,1,1,2,2]
    输出: 2
*/


//解法
/*
    哈希表
    排序找中位数
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> hash_table;
        int len = nums.size();
        for(int i=0;i<len;++i){
            // if(hash_table.find(nums[i])!=hash_table.end()) hash_table[nums[i]] +=1; 
            // else hash_table[nums[i]] = 1;
            ++hash_table[nums[i]];
            if(hash_table[nums[i]]>len/2) return nums[i];
        }
        return -1;
    }
};

//排序找中位数
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};