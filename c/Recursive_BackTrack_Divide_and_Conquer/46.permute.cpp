/*
    46. 全排列
    难度：中等
    给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

/*
    求所有组合，回溯
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
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> item;
        back_track(0,ans,item,nums);
        return ans;
    }
    void back_track(int i,vector<vector<int>>& ans,vector<int>& item,vector<int>& nums){
        if(i == nums.size()){
            return;
        }

        for(int j=0;j<nums.size();++j){             //与17题类似，求全排列需要for循环
            if( find(item.begin(),item.end(), nums[j]) == item.end()){
                item.push_back(nums[j]);
                if(item.size() == nums.size()){
                    ans.push_back(item);
                }
                back_track(i+1,ans,item,nums);      //递归要写在if里面，为什么？因为只要添加进了元素才有回溯
                item.pop_back();                    //回溯，添加了元素进才能回溯，否则会越界
            }
        }
    }
};