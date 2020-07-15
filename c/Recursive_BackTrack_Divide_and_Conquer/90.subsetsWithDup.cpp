/*
    90. 子集II
    难度:中等
    给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

    说明：解集不能包含重复的子集。

示例:
    输入: [1,2,2]
    输出:
         [
         [2],
         [1],
         [1,2,2],
         [2,2],
         [1,2],
         []
         ]

*/

/*
    解法：排序后回溯
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
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;       //最终结果
        vector<int> item;                 //每次递归回溯产生的子集 
        set<vector<int>> res_set;         //去重要用的集合set
        sort(nums.begin(),nums.end());    //排序
        result.push_back(item);
        generate(0, nums, item, result, res_set);

        return result; 
    }
private:
    void generate(int i, vector<int> &nums,
                  vector<int> &item, 
                  vector<vector<int>> &result,
                  set<vector<int>> &res_set){
        if(i==nums.size()){               //递归结束条件
            return;
        }
        item.push_back(nums[i]);
        if(res_set.find(item)== res_set.end()){
            result.push_back(item);
            res_set.insert(item);
        }

        generate(i+1,nums,item,result,res_set);   //递归调用
        item.pop_back();                  //回溯
        generate(i+1,nums,item,result,res_set);   //回溯后的递归调用
    } 
};