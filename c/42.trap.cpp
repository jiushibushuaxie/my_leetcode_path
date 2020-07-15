/*
    42. 接雨水
    难度:困难
    给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

示例:
    输入: [0,1,0,2,1,0,1,3,2,1,2,1]
    输出: 6 

*/

/*
    解法：动态规划
    max_left [i] 代表第 i 列左边最高的墙的高度，max_right[i] 代表第 i 列右边最高的墙的高度。不包括自身。
    三列才能存水，且满足中间一列小于左右两列，存水量为： 短板 - 当前高度。 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        if(!height.size()) return 0;
        vector<int> max_left= vector<int>(height.size(),0);
        vector<int> max_right= vector<int>(height.size(),0);
        for (int i = 1; i < height.size() - 1; i++) {
            max_left[i] = max(max_left[i - 1], height[i - 1]);
        }
        for (int i = height.size()- 2; i >= 0; i--) {   //注意求右最大值是从后往前
            max_right[i] = max(max_right[i + 1], height[i + 1]);
        }
        for (int i = 1; i < height.size() - 1; i++) {
            int min_value = min(max_left[i], max_right[i]);
            if (min_value > height[i]) {
                sum = sum + (min_value - height[i]);
            }
        }
        return sum;
    }
};