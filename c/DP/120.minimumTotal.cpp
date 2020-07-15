/*
    120. 三角形最小路径和
    难度:中等
    给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
    相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。

例如，给定三角形：
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
*/

/*
    解法：动态规划
    方法一：从上到下，需要考虑很多边界条件
    1、子问题：求第i层第j个下标的最优路径和
    2、dp[i][j] 要么等于 dp[i-1][j] + triangle[i][j] 要么等于dp[i-1][j-1] + triangle[i][j]，取小值
    3、边界条件 (1)要判断j-1是否>=0，(2)dp[0][0] = triangle[0][0]等
    4、状态转移方程 

    方法二：从下到上。很简洁
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


//从上到下。有很多边界条件需要考虑
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int> > dp(triangle);  //直接将dp初始化为triangle
        int ans = INT_MAX;
        if (triangle.size() == 1) {
            return triangle[0][0];
        }
        //边界条件
        dp[0][0] = triangle[0][0];
        dp[1][0] = triangle[0][0]+triangle[1][0];
        dp[1][1] = triangle[0][0]+triangle[1][1];
        for(int i=2;i<triangle.size();++i){
            for(int j=0;j<triangle[i].size();++j){
                if(j==0){                   //左边界
                    dp[i][j] = dp[i-1][j] + triangle[i][j];
                }
                else if(j==triangle[i].size() -1) {       //右边界
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                }
                else{                   //正常情况
                    dp[i][j] = min(dp[i-1][j],dp[i-1][j-1]) + triangle[i][j];
                }
            }
        }

        for(int i=0;i<triangle[triangle.size()-1].size();++i){
            ans = min(ans,dp[triangle.size()-1][i]);
        }
        return ans;
    }
};

//从下到上。很简洁
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int> > dp(triangle);  //直接将dp初始化为triangle
        for(int i=triangle.size()-2;i>=0;--i){
            for(int j=0;j<triangle[i].size();++j){
                dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];
            }
        }
        return dp[0][0];
    }
};
