/*
    94. 二叉树的中序遍历
    难度:中等
    给定一个二叉树，返回它的中序 遍历。

示例:
    输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
*/

//解法
/*
    解法：递归与非递归
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x),left(NULL), right(NULL){}
};


class Solution {
public:
    vector<int> res;
    void travel(TreeNode* root){
        if(root==NULL) return;
        travel(root->left);
        res.push_back(root->val);
        travel(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        travel(root);
        return res;
    }
};
