/*
    199. 二叉树的右视图
    难度:中等
    给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

示例:
    输入: [1,2,3,null,5,null,4]
    输出: [1, 3, 4]
    解释:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

*/

/*
    解法：层序遍历
    只把右结点加入队列
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode{
   int val;
   TreeNode* left;
   TreeNode* right;
   TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

//解法1  算法课里的代码
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> q;
        if(!root) return {};
        q.push(root);
        TreeNode* last=root;    //last  每层最后一个节点
        TreeNode * nlast=root;  //nlast  当前队列最后一个节点
        while(q.size()){
            TreeNode* node = q.front();
             q.pop();
            
            if(node->left){
                q.push(node->left);
                nlast = node->left;
            }
            if(node->right){
                q.push(node->right);
                nlast = node->right;
            }
            if(node==last){
                result.push_back(node->val);
                last=nlast; 
            }
        }
        return result;
    }
};

//解法1  视频课里的代码
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> view;
        queue<pair<TreeNode*,int>> Q;       //将节点与第几层绑定
        if(!root) return {};
        Q.push( make_pair(root, 0) );
        while(!Q.empty()){
            TreeNode* node = Q.front().first;
            int depth = Q.front().second;
            Q.pop();
            if(view.size()==depth){         //关键的一步
                view.push_back(node->val);
            }
            else{
                view[depth] = node->val;        //关键的一步
            }
            if(node->left){
                Q.push(make_pair(node->left, depth+1));
            }
            if(node->right){
                Q.push(make_pair(node->right, depth+1));
            }
        }
        return view;
    }
};