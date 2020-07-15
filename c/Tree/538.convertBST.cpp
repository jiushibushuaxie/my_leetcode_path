/*
    538. 把二叉搜索树转换为累加树
    难度:简单
    给定一个二叉搜索树（Binary Search Tree），
    把它转换成为累加树（Greater Tree)，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。

示例
    输入: 原始二叉搜索树:
              5
            /   \
           2     13

输出: 转换为累加树:
             18
            /   \
          20     13


*/

/*
   反向中序遍历， 即 右->本身->左
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
       return root;
    }
    void dfs(TreeNode* node){
        if(!node){
            return;
        }
        dfs(node->right);
        val += node->val;   //中序操作：更新val，val是一个累加的过程
        node->val = val;    //将val的值赋给当前节点
        dfs(node->left);
    }
private:
    int val = 0;
};