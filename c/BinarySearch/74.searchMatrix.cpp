/*
    74. 搜索二维矩阵
    难度：中等
    编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：

    每行的元素从左到右升序排列。
    每行的第一个整数大于前一行的最后一个整数。

示例:
    输入:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
输出: true

*/


//解法
/*
    二维数组的二分查找
    把二维当成一维来做
    matrix[ mid/n ][ mid%n ] 注意，n为列数！！！！，一定是对列数取商取余！！！！
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size()) return false;
        int m =  matrix.size(); int n = matrix[0].size();
        int left = 0;
        int right = m*n-1;
        while(left<=right){
            int mid = left+ (right - left)/2;
            if(matrix[mid/n][mid%n]<target){
                left = mid+1;
            }
            else if(matrix[mid/n][mid%n]>target){
                right = mid-1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};