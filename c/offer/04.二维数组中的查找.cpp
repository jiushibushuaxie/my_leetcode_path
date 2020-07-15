/*

在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

示例:
现有矩阵 matrix 如下：
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
给定 target = 5，返回 true。
给定 target = 20，返回 false。
*/

/*
    右上到左下
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(!matrix.size()) return false;
        int i = 0;
        int j = matrix[0].size()-1;
        while(i<matrix.size()&&j>=0){
            if(matrix[i][j]==target){
                return true;
            }
            else if(matrix[i][j]>target) {
                --j;
            }
            else if(matrix[i][j]<target) {
                ++i;
            }
        }
        return false;
    }
};