/*
    226. 翻转二叉树
    难度:简单
    翻转一棵二叉树。

示例：

输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9

输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1

*/

/*
    递归
    就是前中后序遍历，多了个swap
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
    void swap(TreeNode*& left, TreeNode*& right){  //swap传引用
        TreeNode* temp = left;
        left = right;
        right = temp;
    }

    TreeNode* invertTree(TreeNode* root) {
        preorder(root);
        return root;
    }

    //1、先序
    void preorder(TreeNode* node){
        if (node == NULL){
            return;
        }
        swap(node->left, node->right);
        preorder(node->left);
        preorder(node->right);
    }

    //2、中序
    void inorder(TreeNode* node){
        if (node == nullptr){
            return;
        }
        inorder(node->left);
        swap(node->left, node->right);
        inorder(node->left);
    }

    //3、后序
    void postprder(TreeNode* node){
        if (node == nullptr){
            return;
        }
        postprder(node->left);
        postprder(node->right);
        swap(node->left, node->right);
    }
};



    