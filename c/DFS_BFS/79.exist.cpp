/*
    79. 单词搜索
    难度：中等
    给定一个二维网格和一个单词，找出该单词是否存在于网格中。
    单词必须按照字母顺序，通过相邻的单元格内的字母构成，
    其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
    同一个单元格内的字母不允许被重复使用。

示例:
board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

    给定 word = "ABCCED", 返回 true
    给定 word = "SEE", 返回 true
    给定 word = "ABCB", 返回 false

提示：

    board 和 word 中只包含大写和小写英文字母。
    1 <= board.length <= 200
    1 <= board[i].length <= 200
    1 <= word.length <= 10^3

//解法
/*
    回溯
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> mark(board.size(),vector<bool>(board[0].size(),false));
        for(int i=0;i<board.size();++i){            // 二维表格的每一个格子都可以为出发点
            for(int j=0;j<board[0].size();++j){
                if(backtrack(i, j, board,mark,0, word)){
                    return true;
                }
            }
        }
        return false;
    }

    bool backtrack(int i,int j,vector<vector<char>>& board,
                    vector<vector<bool>>& mark,
                    int word_index, string word){
        if(board[i][j]!=word[word_index]){                     //递归终止条件1
            return false;                   // 当前位的字母不相等，此路不通
        }
        //word_index标记的是匹配word的字符下标。当匹配搭配最后一个字符时，return true
        if(word_index==word.size()-1){  //递归终止条件2
                return true;
        }
        
        mark[i][j] = true;          //true代表被访问过
        word_index++;
        char tmp = board[i][j];      //回溯用，暂存当前状态
        
        //用到了或运算的性质，一个一个的进行判断
        if((i > 0 && !mark[i-1][j] && backtrack(i-1, j, board,mark,word_index, word)) // 往上走
        || (j > 0 && !mark[i][j-1] && backtrack(i, j-1, board,mark,word_index, word)) // 往左走
        || (i < board.size() - 1 && !mark[i+1][j] && backtrack(i+1, j, board,mark,word_index, word)) // 往下走
        || (j < board[0].size() - 1 && !mark[i][j+1] && backtrack(i, j+1, board,mark,word_index,word))){ // 往右走
            return  true; // 其中一条能走通，就算成功
        }
        
        board[i][j] = tmp; // 如果都不通，则回溯上一状态
        mark[i][j] = false;
        return false;  
    }
};