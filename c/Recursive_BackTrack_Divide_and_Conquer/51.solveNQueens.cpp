/*
    51. N皇后
    难度:困难
    n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

示例:

    输入: 4
    输出: [
    [".Q..",  // 解法 1
    "...Q",
    "Q...",
    "..Q."],

    ["..Q.",  // 解法 2
    "Q...",
    "...Q",
    ".Q.."]
    ]
    解释: 4 皇后问题存在两个不同的解法。

*/

/*
    解法：回溯
    如何设计算法与数据存储？
    1、二维数组进行数据存储  1代表不可以放置皇后，0可以
    2、设置方向数组  ，理解方向数组
    每行都要放置皇后且只能放置一个
    回溯过程中记得恢复mark数组
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;  //所有可行的解法，即最后结果
        vector<string> location(n, string(n,'.'));          //一次可行的解法,初始化为  ...
        vector<vector<int>> mark(n,vector<int>(n,0));       //棋盘初始化为0

        generate(0,n,result,location,mark);
        return result;
    }

private:
    void put_down_the_queen(int x, int y, vector<vector<int>>& mark) {   
        //理解方向数组,在x,y放置queen
        static const int dx[] = {-1,1,0,0,-1,-1,1,1};   //方向数组x
        static const int dy[] = {0,0,-1,1,-1,1,-1,1};   //方向数组y
        mark[x][y] = 1;
        for(int i=1;i<mark.size();++i){
            for(int j=0;j<8;++j){                       //8代表八个方向，每个方向向外延伸1至N-1，所有i=1
                int new_x =x + i*dx[j];
                int new_y =y + i*dy[j];

                if(new_x>=0 && new_y>=0 && new_x<mark.size() && new_y<mark.size()){
                    mark[new_x][new_y] = 1;
                }
            }
        }
    }

    void generate(int k,int n,   
                  vector<vector<string>>& result,
                  vector<string>& location,
                  vector<vector<int>>& mark){            
    //k代表完成了k个皇后的放置，或正在放置第k行的皇后
        if(k==n){                       //结束递归条件
            result.push_back(location);         //存储一次结果
            return;
        }
        for(int i=0;i<n;++i){           //按列放置皇后，因为k已经代表了行，用i代表列
            if(mark[k][i]==0){                       //满足条件，可以放置皇后
                vector<vector<int>> tmp_mark = mark;   //记录回溯前的mark;
                location[k][i] = 'Q';
                put_down_the_queen(k,i,mark);          //放置queen,更新棋盘mark
                generate(k+1,n,result,location,mark);  //递归
                mark = tmp_mark;                       //要是执行到这一步，则必定是回溯，回溯要做的两件事 其一                       
                location[k][i] = '.';                  //其二
            }
        }
    }
};