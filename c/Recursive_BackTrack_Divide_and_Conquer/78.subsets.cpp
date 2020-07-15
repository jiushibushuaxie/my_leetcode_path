/*
    78. 子集
    难度:中等
    给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

    说明：解集不能包含重复的子集。

示例:
    输入: nums = [1,2,3]
    输出:
        [
        [3],
        [1],
        [2],
        [1,2,3],
        [1,3],
        [2,3],
        [1,2],
        []
        ]

*/

/*
    解法1：回溯，主要是用了两次递归
    模拟是否选择某一元素？
    解法2：位运算
    下标组成一串二进制
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

//回溯
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;       //最终结果
        vector<int> item;                 //每次递归回溯产生的子集 
        result.push_back(item);
        generate(0,nums,item,result);

        return result; 
    }
private:
    void generate(int i, vector<int> &nums, vector<int> &item, vector<vector<int>> &result){
        if(i==nums.size()){               //递归结束条件
            return;
        }
        item.push_back(nums[i]);
        result.push_back(item);

        generate(i+1,nums,item,result);   //递归调用
        item.pop_back();                  //回溯
        generate(i+1,nums,item,result);   //回溯后的递归调用
    } 
};

//位运算
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;       //最终结果
        int all_set = 1<<nums.size();     //1<<n 即 2^n;  1向左移n位

        for (int i=0;i<all_set;++i){
            vector<int> item;
            for (int j=0;j<nums.size();++j) {
                if (i&(1<<j))                   //1<<j即nums数组中的第j个元素
                    item.push_back(nums[j]);
            }
            result.push_back(item);
        } 
        return result;
    }
}；