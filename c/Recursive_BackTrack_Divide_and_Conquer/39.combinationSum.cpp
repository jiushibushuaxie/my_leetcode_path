/*
    39. 组合总和
    难度:中等
    给定一个无重复元素的数组 candidates 和一个目标数 target ，
    找出 candidates 中所有可以使数字和为 target 的组合。
    candidates 中的数字可以无限制重复被选取。

说明：

    所有数字（包括目标数）都是正整数。
    解集不能包含重复的组合。 

示例 1:

    输入: candidates = [2,3,6,7], target = 7,
    所求解集为:
    [
    [7],
    [2,2,3]
    ]

示例 2:

    输入: candidates = [2,3,5], target = 8,
    所求解集为:
    [
    [2,2,2,2],
    [2,3,3],
    [3,5]
    ]

*/

/*
    解法：回溯+剪枝

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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> candidate_array;
        getCombination(res, candidates, candidate_array, 0, target, 0);
        return res;
    }
    void getCombination(vector<vector<int>> &res, vector<int>& candidates,
                        vector<int> &candidate_array, int partial_sum, int &target, int idx){
        if(partial_sum == target){
            res.push_back(candidate_array);
        }else if(partial_sum > target){
            return;
        }else{// partial_sum < target
            for(int i = idx; i < candidates.size(); ++i){
                candidate_array.push_back(candidates[i]);
                getCombination(res, candidates, candidate_array, partial_sum + candidates[i], target, i);
                candidate_array.pop_back();     //回溯
            }
        }
    }
};

