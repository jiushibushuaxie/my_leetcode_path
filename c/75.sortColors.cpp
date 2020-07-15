/*
    75. 颜色分类
    难度：中等
    给定一个包含红色、白色和蓝色，一共 n 个元素的数组，
    原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
    此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

注意:
    不能使用代码库中的排序函数来解决这道题。
*/

//解法
/*
    荷兰国旗问题

    用三个指针（p0, p2 和curr）来分别追踪0的最右边界，2的最左边界和当前考虑的元素。

    While curr <= p2 :    注意是小于等于
    若 nums[curr] = 0 ：交换第 curr个 和 第p0个 元素，并将指针都向右移。
    若 nums[curr] = 2 ：交换第 curr个和第 p2个元素，并将 p2指针左移 。
    若 nums[curr] = 1 ：将指针curr右移。
    因为curr左边的值已经扫描过了，所以curr要++继续扫描下一位，
    而与p2交换的值，curr未扫描，要停下来扫描一下，所以curr不用++。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0;
        int cur = 0;
        int p2 = nums.size()-1;
        while(cur<=p2){
            if(nums[cur]==0){
                swap(nums[p0],nums[cur]);
                ++p0;
                ++cur;
            }
            else if(nums[cur]==1){
                ++cur;
            }
            else if(nums[cur]==2){
                swap(nums[cur],nums[p2]);
                --p2;
            }
        }
        return;
    }
};