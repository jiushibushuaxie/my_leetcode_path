/*
    300. 最长上升子序列
    难度:中等
    给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:
    输入: [10,9,2,5,3,7,101,18]
    输出: 4 
    解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。

*/

/*
    解法：动态规划 

    方法一、
    1、子问题：
    2、dp[i]代表  以第i个元素结尾的  最长上升子序列长度,例如
    [1,3,2,3,1,4] dp[0] = 1; dp[1] = 2  {1,3}; dp[2] = 2  {1,2}; dp[3] = 2  {1,2,3}; dp[4]=1 {1}
    3、边界条件  
    4、状态转移方程  dp[i] = max(dp[i],dp[j] + 1);  

    方法二、stack[i] 代表 长度为i+1的上升子序列 最后一个元素的最小可能取值
    最终栈的大小就是最长上升子序列长度
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

//视频方法一
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 0;
        if(nums.size()==0) {
            return 0;
        }
        vector<int> dp(nums.size(),1);            //初始化为1

        for(int i=0; i<nums.size(); ++i){                 //两个for循环
            for (int j = 0; j < i; ++j) {            //两个for循环
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i],dp[j] + 1);    //关键一步，类似与53题，最大子序和，只是这里是求长度
                }
            }
            res = max(dp[i],res);
        }
        return res;
    }
};


//视频方法二，用栈（使用vector实现）
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0) {
            return 0;
        }
        vector<int> stack;
        stack.push_back(nums[0]);
        for(int i=1;i<nums.size();++i){
            if(nums[i]>stack.back()){
                stack.push_back(nums[i]);
            }
            else{
                for(int j=0;j<stack.size();++j){
                    if(stack[j]>=nums[i]){
                        stack[j] = nums[i];
                        break;
                    }
                }
            }
        }
        return stack.size();
    }
};




