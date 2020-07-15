/*
    45. 跳跃游戏 II
    难度:困难
    给定一个非负整数数组，你最初位于数组的第一个位置。
    数组中的每个元素代表你在该位置可以跳跃的最大长度。

    你的目标是使用<最少的>跳跃次数到达数组的最后一个位置。

示例:
    输入: [2,3,1,1,4]
    输出: 2
    解释: 跳到最后一个位置的最小跳跃数是 2。
    从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。

说明:
    假设你总是可以到达数组的最后一个位置。
*/

/*
    解法：贪心
    尽量少跳，不得已再跳
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
    int jump(vector<int>& nums) {
        if(nums.size()<2){
            return 0;
        }
        int min_jump = 1;
        int cur_max_index = nums[0];        //当前可到达最远位置
        int pre_max_index = nums[0];        //遍历各个位置过程中，可达到的最远位置

        for(int i=1;i<nums.size();++i){
            if(i>cur_max_index){                 //i无法再向前移动了，这时候需要跳一步使cur_max_index增大
                ++min_jump;                      //需要跳一步，所以++min_jump
                cur_max_index = pre_max_index;   //怎么跳cur_max_index最大，跳之前范围内最大的那一步
            }
            if(pre_max_index<nums[i]+i){        //更新pre_max_index
                pre_max_index = nums[i]+i;
            }
        }
        return min_jump;
    }
};