/*
    98. 验证二叉搜索树
    难度:中等
    给定一个二叉树，判断其是否是一个有效的二叉搜索树。

    假设一个二叉搜索树具有如下特征：

        节点的左子树只包含小于当前节点的数。
        节点的右子树只包含大于当前节点的数。
        所有左子树和右子树自身必须也是二叉搜索树。


示例 1:

输入:
    2
   / \
  1   3
输出: true

示例 2:
输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。

*/

//解法
/*
    二叉搜索树中序遍历后，为升序
    注意了[10,5,15,null,null,6,20]不是一个二叉搜索树
    因为6在10的右子树里面
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x),left(NULL), right(NULL){}
};

//中序递归遍历
class Solution {
public:
    long left_val = LONG_MIN;           //这个long_min是初始值。
    bool isValidBST(TreeNode* root) {
        if(!root){
            return true;    //空子树是二叉搜索树
        }
        
        if(isValidBST(root->left)){     //这个if判断语句就相当于递归左子树了
            if(left_val>=root->val){        //中间做错误情况的判断
                return false;
            }
            left_val = root->val;
            return isValidBST(root->right);     //return就相当于递归右子树了
        }
        return false;
    }
};

//非递归中序遍历
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> S;
        TreeNode* node = root;
        long left_val = LONG_MIN;           //这个long_min是初始值。

        while(node||!S.empty()){
            while(node){
                S.push(node); 
                node = node->left;
            }
            node = S.top();
            S.pop();

            if (node->val <= left_val) {
                return false;
            }
            left_val = node->val;

            node=node->right;
        }
        return true;
    }
};


