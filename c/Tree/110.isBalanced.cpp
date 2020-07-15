/*
    110. 平衡二叉树
    判断一个二叉树是否为平衡二叉树：左右子树高度相差不超过1 
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//1、判断一个二叉树是否为平衡二叉树
//二叉树很多问题都是递归方法
//自顶向下的递归
class IsBalanceTree{
public:
    //计算高度
    int level(TreeNode *root){
        if(root == nullptr) return 0;  //当结点为空时，没有高度，为0
        return max(level(root->left),level(root->right)) +1;  //否则当前结点的高度为左右子节点最大高度加1
    }

    //判断一个二叉树是否平衡了
    bool isBalanced(TreeNode *root){
        if(root == nullptr)  return true;  // 空树为平衡树
        int factor = abs(level(root->left)-level(root->right));  //左右子树高度差
        // 高度差小于2 且左右子树也是平衡的
        return factor<2 && isBalanced(root->left) && isBalanced(root->right);  
    }
};

//改进方法  
//自底向上的递归
//自底向上与自顶向下的逻辑相反，首先判断子树是否平衡，然后比较子树高度判断父节点是否平衡。
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return CheckBalance(root)>=0;
    }
    int CheckBalance(TreeNode* root){
        if(!root)return 0; //空结点，说明到达底部，返回高度0

        int Lh=CheckBalance(root->left);//检查左子树高度
        if(Lh<0)//高度是否满足，负数相当于false，继续返回
            return Lh;

        int Rh=CheckBalance(root->right);//检查右子树高度
        if(Rh<0)//负数为false，直接返回
            return Rh;
            
        //左右子树都满足高度合法，检查当前根节点是否满足
        if(abs(Lh-Rh)<2)
            return max(Lh,Rh)+1;//满足，返回新的高度
        else
            return -1;//不满足，返回负数相当于false
    }
};





