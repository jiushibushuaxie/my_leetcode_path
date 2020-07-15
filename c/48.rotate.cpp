/*
    48. 旋转图像  
    难度：中等
    给定一个 n × n 的二维矩阵表示一个图像。
    将图像顺时针旋转 90 度。
   
    说明：
    你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。
    
示例 1:
    给定 matrix = 
    [
    [1,2,3],
    [4,5,6],
    [7,8,9]
    ],

    原地旋转输入矩阵，使其变为:
    [
    [7,4,1],
    [8,5,2],
    [9,6,3]
    ]

示例 2:
    给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
*/

//解法
/*
    row,colum分别代表行、列  
    [i][j]  -> [j][row-i]; 旋转一行需要遍历列数
    怎么原地修改，不使用额外空间呢?
    对角线 ：按着左上到右下的对角线翻转 \
    反对角线：按着右上到左下的对角线翻转 /
    竖轴：按着平行于y轴的中心线翻转 |
    横轴： 按着平行于x轴的中心线翻转 ——
    都为顺时针
    对角线 + 竖轴 = 90° 
    对角线 + 横轴 = 270°
    反对角线 + 竖轴 = 270°
    反对角线 + 横轴 = 90°
    横轴 + 竖轴 = 180°

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        // 对于正对角线对称翻转
        for (int i = 0; i < n; i++) {
            for (int j = i; j < m; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // 竖轴镜像操作
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        // 对于反正对角线对称翻转
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n-1-i; j++) {
                swap(matrix[i][j], matrix[n-1-j][n-1-i]);
            }
        }
        // 横轴镜像操作
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n/2; i++) {
                swap(matrix[i][j], matrix[n-1-i][j]);
            }
        }
    }
};
