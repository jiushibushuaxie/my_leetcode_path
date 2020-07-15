/*
    101. 对称二叉树
    难度:简单
    给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3

但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3

*/

/*
    解法：动态规划
    
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}    
};

//递归
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return helper(root,root);
    }
    bool helper(TreeNode* left,TreeNode* right){
        if(!left&&!right) return true;     //递归终止条件 都不存在，return true
        if(!left || !right) return false;      //或者两个节点中有一个为空,这里用到或运算的性质
        if(left->val!=right->val)  return false;       //不相等，return false
        
        return helper(left->left,right->right) && helper(left->right,right->left);
    }
};

//迭代,层序遍历
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root== NULL) return true;

        queue<TreeNode*> Q;
        Q.push(root->left);
        Q.push(root->right);
        while(!Q.empty()){
            TreeNode* left = Q.front();
            Q.pop();
            TreeNode* right = Q.front();
            Q.pop();
            if(left==NULL && right==NULL){
                continue;                       //注意这里是continue，而不是return true,队列为空时，才return true
            }
            if(left==NULL || right==NULL){
                return false;
            }
            if(left->val == right->val){        //进队列顺序要对
                Q.push(left->left);             //不管push进去的是不是空节点
                Q.push(right->right);

                Q.push(left->right);
                Q.push(right->left);
            }
            else if(left->val != right->val){
                return false;
            }
        }
        return true;
    }
};