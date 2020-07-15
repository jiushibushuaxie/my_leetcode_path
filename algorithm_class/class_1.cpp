//问题描述
/*
    有一棵二叉树，请设计一个算法，按照层次打印这棵二叉树。
    给定二叉树的根结点root，请返回打印结果，结果按照每一层一个数组进行储存，所有数组的顺序按照层数从上往下，
    且每一层的数组内元素按照从左往右排列。保证结点数小于等于500。

*/

//解法
/*
    层序遍历，用队列打印二叉树的值
    定义last和nlast，用于打印第几行
    queue q;
    q.front() 返回队头
*/

#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>

using namespace std;


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
 
class TreePrinter {
public:
    vector<vector<int> > printTree(TreeNode* root) {
       vector<vector<int>> res;
        if(root==NULL)
        {
            return res;
        }
        TreeNode* last=root;    //last
        TreeNode * nlast=root;  //nlast
        queue<TreeNode *> q;    //定义一个队列,队列里面是二叉树的结点
        q.push(root);           
        vector<int> vec;
        while(!q.empty())
        {
            TreeNode * cur=q.front();   //队头
            q.pop();                    //先pop队头
            if(cur->left)               //如果队头存在左子结点
            {                           //二叉树先左后右
                q.push(cur->left);      //把左子节点放进队列
                nlast=cur->left;        //nlast等于左子结点的值
            }
            if(cur->right)              //如果队头存在右子结点
            {
                q.push(cur->right);     //把右子节点放进队列
                nlast=cur->right;       //nlast等于右子结点的值
            }
            vec.push_back(cur->val);    
            if(cur==last)               //如果pop出的队头的值等于last
            {
                res.push_back(vec);     //保存当前数组
                vec.clear();            //vec清空
                last=nlast;             //将nlast的值赋给last;
            }
        }
        return res;
    }
};