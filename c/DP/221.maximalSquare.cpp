//问题描述
/*
    221. 最大正方形
    难度:中等
    在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。

示例:

    输入: 

    1 0 1 0 0
    1 0 1 1 1
    1 1 1 1 1
    1 0 0 1 0
    输出: 4

*/


//解法
/*
    解法：动态规划DP[i][j] = min(DP[i-1][j],min(DP[i-1][j-1],DP[i][j-1])) + 1;
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

class Solution {    
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if(row == 0) return 0;
        int column = matrix[0].size();
        vector<vector<char>> DP(row, vector<char>(column,0));
        int maxSquare = 0;
        for(int i=0;i<row;++i){
            for(int j=0;j<column;++j){
                if(matrix[i][j]=='1'){    //注意是char型
                    if(i>0&&j>0){
                        DP[i][j] = min(DP[i-1][j],min(DP[i-1][j-1],DP[i][j-1])) + 1;
                    }
                    else DP[i][j] = 1;
                    if(maxSquare<DP[i][j])  maxSquare = DP[i][j];
                }
            }
        }
    return maxSquare*maxSquare;
    }
};

int main()
{
    Solution solver;
    vector<vector<char>> matrix = {};
    int a = solver.maximalSquare(matrix);
    cout<<a<<endl;
    return 0;
}
