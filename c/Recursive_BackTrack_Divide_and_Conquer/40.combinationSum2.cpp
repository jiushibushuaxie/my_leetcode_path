/*
    40. 组合总和 II
    难度:中等
    给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

    candidates 中的每个数字在每个组合中只能使用一次。

说明：

    所有数字（包括目标数）都是正整数。
    解集不能包含重复的组合。 

示例 1:

    输入: candidates = [10,1,2,7,6,1,5], target = 8,
    所求解集为:
    [
    [1, 7],
    [1, 2, 5],
    [2, 6],
    [1, 1, 6]
    ]

示例 2:

    输入: candidates = [2,5,2,1,2], target = 5,
    所求解集为:
    [
    [1,2,2],
    [5]
    ]


*/

/*
    解法：回溯+剪枝
    主要讲剪枝
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
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> item;
        set<vector<int>> res_set;  
        sort(candidates.begin(),candidates.end());
        generate(0, candidates, 0, target, result, item, res_set);  

        return result;
    }
private:
    void generate(int i, vector<int>& candidates, int sum,
                  int target, vector<vector<int>>& result,
                  vector<int>& item, set<vector<int>>& res_set) {
        if(sum>target||i==candidates.size()){           //递归结束条件，有剪枝判断sum>target
            return;
        }      
        sum += candidates[i];
        item.push_back(candidates[i]);
        if(sum==target && res_set.find(item)== res_set.end()){
            result.push_back(item);
            res_set.insert(item);
        }
        generate(i+1, candidates, sum, target, result, item, res_set);
        sum -= candidates[i];           //回溯后，要讲sum进行减法操作，很关键也很容易忘记
        item.pop_back();
        generate(i+1, candidates, sum, target, result, item, res_set);
    }
};