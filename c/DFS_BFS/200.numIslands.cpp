/*
    200. 岛屿数量
    难度：中等
    给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
    岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。
    此外，你可以假设该网格的四条边均被水包围。

示例 1:
    输入:
    11110
    11010
    11000
    00000
    输出: 1
示例 2:
    输入:
    11000
    11000
    00100
    00011
    输出: 3
    解释: 每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。
*/

//解法
/*
    回溯是有几种排列情况，搜索是有几个局部体，都会用到递归
    很经典
    DFS，
    深度优先遍历，对应树的前序遍历
    遍历整个数组，遇到1，ans++，ans是记录岛的个数的
    运行一下dfs函数，把这个岛所有陆地给我沉喽，这个岛全部的1变成0
    等把grid全遍历完，grid就全是0了，再把ans输出，这个ans就是我们记录的岛的个数

    BFS，用到队列，与二叉树的层序遍历是一样的
    先不管那么多，先push进队列
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[i].size();++j){
                if(grid[i][j] == '1'){
                    ans++;
                    DFS(grid,i,j);
                }
            }
        }
        return ans;
    }

    void DFS(vector<vector<char>>& grid,int x,int y){
        if(x<0||x>=grid.size()||y<0||y>=grid[x].size()){        //超出索引，结束递归
            return;
        }                        //一、递归结束条件
        if(grid[x][y]=='0'){                 //不是陆地，结束递归
            return;
        }
        grid[x][y] = '0';       //二、标记访问过的位置，把访问过的陆地炸沉
        static const int dx[] ={-1, 1, 0, 0};
        static const int dy[] ={ 0, 0,-1, 1};       //方向数组
        for(int i=0;i<4;++i){
            int newx = x+dx[i];
            int newy = y+dy[i]; 
            DFS(grid,newx,newy);    //三、执行递归
            //因为有了最前面的递归终止条件，放心的继续深搜
        }
        return;
    }

    void BFS(vector<vector<char>>& grid,int& ans){
        queue<pair<int,int>> Q;     //队列保存的是下标
        static const int dx[] ={-1, 1, 0, 0};
        static const int dy[] ={ 0, 0,-1, 1};       //方向数组

        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]=='1'){
                    ans++;                  //先ans++;
                    Q.push(make_pair(i,j));         //遇到’1‘就push进队列，同时标记为’0‘
                    grid[i][j] = '0';               //标记访问过的位置，
                    while(!Q.empty()){              //队列非空时
                        pair<int,int> node=Q.front();       //取队头，并pop队头
                        Q.pop();
                        for(int k=0;k<4;++k){       //访问上下左右，不超出索引，且为’1‘，push进队列，同时置为’0‘
                            int x = node.first + dx[k];
                            int y = node.second+ dy[k];
                            if(x>=0 && x<grid.size() && y>=0 && y<grid[0].size() && grid[x][y]=='1'){   
                                Q.push(make_pair(x,y));
                                grid[x][y]='0';     //同时置为’0‘。标记访问过的位置，
                            }                  
                        }
                    }
                }
            }
        }
        return;
    }
};