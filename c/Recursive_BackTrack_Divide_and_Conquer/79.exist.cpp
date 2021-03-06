//问题描述
/*
    79. 单词搜索
    难度:中等
    给定一个二维网格和一个单词，找出该单词是否存在于网格中。
    单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
    同一个单元格内的字母不允许被重复使用。

示例 1:
    board =
    [
    ['A','B','C','E'],
    ['S','F','C','S'],
    ['A','D','E','E']
    ]

    给定 word = "ABCCED", 返回 true
    给定 word = "SEE", 返回 true
    给定 word = "ABCB", 返回 false

*/


//解法
/*
    解法：使用深度优先搜索（DFS）和回溯的思想实现。
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
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(backtrack(board, word, 0, i , j)){  // 二维表格的每一个格子都可以为出发点
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool backtrack(vector<vector<char>>& board, string& word, int wordIndex, int x, int y){
        if( board[x][y] != word[wordIndex]){ // 当前位的字母不相等，此路不通
            return false;
        }
        //wordIndex标记的是匹配word的字符下标。当匹配搭配最后一个字符时，return true
        if(word.size() - 1  == wordIndex){ // 最后一个字母也相等, 返回成功
            return true;
        }
        char tmp = board[x][y];     //回溯用，暂存当前状态
        board[x][y] = 0;            // 标记数组，避免该位重复使用
        wordIndex++;
        if((x > 0 && backtrack(board, word, wordIndex, x - 1, y)) // 往上走
        || (y > 0 && backtrack(board, word, wordIndex, x, y - 1)) // 往左走
        || (x < board.size() - 1 && backtrack(board, word, wordIndex, x + 1, y)) // 往下走
        || (y < board[0].size() - 1 && backtrack(board, word, wordIndex, x, y + 1))){ // 往右走
            return  true; // 其中一条能走通，就算成功
        }
        board[x][y] = tmp; // 如果都不通，则回溯上一状态
        return false;
    }
};
