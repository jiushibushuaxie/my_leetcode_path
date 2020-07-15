/*
    112. 路径总和
    难度:简单
    给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

    说明: 叶子节点是指没有子节点的节点。

示例
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1

返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。
*/

/*
    注意是根节点到叶子节点
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

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root){
            return false;
        }
        if(root->left==NULL&&root->right==NULL&&sum==root->val){        //根节点到叶子节点
            return true;
        }
        bool left_bool = hasPathSum(root->left, sum- root->val);
        bool right_bool = hasPathSum(root->right, sum- root->val);
        return left_bool||right_bool;
    }
};