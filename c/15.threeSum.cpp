/*
    15. 三数之和
    给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？
    请你找出所有满足条件且不重复的三元组。
    注意：答案中不可以包含重复的三元组。

示例：

    给定数组 nums = [-1, 0, 1, 2, -1, -4]，
    满足要求的三元组集合为：
    [
    [-1, 0, 1],
    [-1, -1, 2]
    ]

*/

//解法
/*
    排序+双指针
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
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        vector<vector<int> > res;
        //第一个数做for循环，其余两个数分别为left right;
        for (int i = 0; i < N - 2; ++i) {       //i最多只能到N-2,因为要三数之和
            if (nums[i] > 0) break;             //nums[i]>0时，后面都大于0了，三数之和肯定大于0
            if (i > 0 && nums[i] == nums[i - 1]) continue;      //对第一个数去重
            int l = i + 1;                      // left指针为 i-1
            int r = N - 1;                      // right指针一直是N-1
            while (l < r) { 
                int sum = nums[i] + nums[l] + nums[r];
                if (sum > 0) {
                    --r;
                } else if (sum < 0) {
                    ++l;
                } else {
                    res.push_back({nums[i], nums[l], nums[r]}); 
                    while (l < r && nums[l] == nums[++l]);      //left去重
                    while (l < r && nums[r] == nums[--r]);      //right去重
                }
            }
        }
        return res;
    }
};