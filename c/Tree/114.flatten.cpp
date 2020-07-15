/*
    114. 二叉树展开为链表
    难度:中等
    给定一个二叉树，原地将它展开为一个单链表。
    前序遍历

    例如，给定二叉树

            1
           / \
          2   5
         / \   \
        3   4   6
    将其展开为：
        1
         \
          2
           \
            3
             \
              4
               \
                5
                 \
                  6
*/

/*
    解法：后序遍历、递归, 很经典~~~~自己想的
    不允许使用vector
    直接是转为TreeNode 形式的单链表
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root){
            return;
        }
        
        flatten(root->left);
        flatten(root->right);

        if(root->right&&root->left){        //情况一，左右都有子节点 
            TreeNode* temp = root->left;             //保存左结点为临时节点
            while(temp->right) temp =temp->right;    //找到左子节点的最右节点， 
            temp->right = root->right;               //连接最右节点与临时节点
            //此时完成左子节点的全部操作
            root->right = root->left;                //将左节点变为右结点,注意这里不能写成root->right = temp; 因为temp变为左子节点的最后一个节点了
            root->left = NULL;                       //不要忘记左节点为空
        }
        if(root->left&&!root->right){       //情况二，只有左子节点
            root->right = root->left;
            root->left = NULL;
        }
        
        return;
    }
};

void preorder(TreeNode* root){
    if(!root){
        return;
    }
    cout<<root->val<<' ';
    preorder(root->left);
    preorder(root->right);
    return;
}

int main()
{
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);
    node1->left = node2;
    node1->right = node5;
    node2->left = node3;
    node2->right = node4;
    node5->right = node6;
    
    Solution solver;
    solver.flatten(node1);
    preorder(node1);

    return 0;
}
