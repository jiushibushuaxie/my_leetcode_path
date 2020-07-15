/*
    64. 最小路径和
    难度：中等
    给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
    说明：每次只能向下或者向右移动一步。

示例:
    输入:
    [
    [1,3,1],
    [1,5,1],
    [4,2,1]
    ]
    输出: 7
    解释: 因为路径 1→3→1→1→1 的总和最小。

*/

//解法
/*
    动态规划
    1、子问题 走到坐标为i,j的最小路径dp[i][j]
    2、边界条件  i-1>=0,j-1>=0
    3、状态转移方程 dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(), 0));
        int ans = 0;
        dp[0][0] = grid[0][0];
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(i-1<0&&j-1>=0){
                    dp[i][j] = dp[i][j-1]+grid[i][j];
                }
                if(j-1<0&&i-1>=0){
                    dp[i][j] = dp[i-1][j]+grid[i][j];
                }
                else if(j-1>=0&&i-1>=0){
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
                }
            }
        }
        ans = dp[grid.size()-1][grid[0].size()-1];
        return ans;
    }
};