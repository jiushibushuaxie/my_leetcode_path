/*
    54. 螺旋矩阵
    难度：中等
    给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

示例 1:

输入:
    [
    [ 1, 2, 3 ],
    [ 4, 5, 6 ],
    [ 7, 8, 9 ]
    ]
输出: [1,2,3,6,9,8,7,4,5]


*/

//解法
/*
    两种方法
    方法一、改变边界
    方法二、利用方向数组
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> ans;
        if(matrix.empty()) return ans; //若数组为空，直接返回答案
        int u = 0; //赋值上下左右边界
        int d = matrix.size() - 1;
        int l = 0;
        int r = matrix[0].size() - 1;
        while(true){
            //向右
            for(int i = l; i <= r; ++i) {
                ans.push_back(matrix[u][i]);//向右移动直到最右
            }
            u++;                        //重新设定上边界
            if( u > d) break;           //若上边界大于下边界，则遍历遍历完成，下同

            //向下
            for(int i = u; i <= d; ++i) {       
                ans.push_back(matrix[i][r]);
            }
            r--;                        //重新设定右边界
            if(r < l) break; 

             //向左
            for(int i = r; i >= l; --i) {
                ans.push_back(matrix[d][i]);        
            }       
            d--;                        //重新设定下边界
            if( d < u) break; 

             //向上
            for(int i = d; i >= u; --i) {
                ans.push_back(matrix[i][l]);
            }
            l++;                        //重新设定左边界
            if( l > r) break; 
        }
        return ans;
    }
};



class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        vector<int> res;        //定义一维数组
        int m = matrix.size();  //定义行为m，列为n
        int n = matrix[0].size();
        vector<vector<bool>> st(m,vector<bool>(n,false)); //定义一个二维bool型数组，判定是否数组访问过
        int dx[4]={0, 1, 0, -1}, dy[4]={1, 0, -1, 0}; //定义右下左上 方向数组
        
        int x = 0, y = 0, d = 0; //从（0，0）开始遍历，d = 0表示先从右边开始
        for (int i = 0; i < n * m; i ++) { //访问n*m次
            res.push_back(matrix[x][y]); //将访问的数保存至res一维数组
            st[x][y] = true; //将访问的数定义为false
            int a = x + dx[d], b= y + dy[d];
            if (a < 0 || a >= m || b < 0 || b >= n || st[a][b] ) {      //超出边界或访问过
                d = (d + 1) % 4;            //改变方向
                a = x + dx[d], b = y + dy[d];
            }
            x = a, y = b;
        }
        return res;
    }
};
