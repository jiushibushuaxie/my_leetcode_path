/*
    113. 路径总和 II
    难度:中等
    给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1

返回:
    [
        [5,4,11,2],
        [5,8,4,5]
    ]

*/

//解法
/*
    解法：前序 回溯
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};


class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
         vector<vector<int>> result;
         vector<int> item;
         generate(root,result,item, sum);
         return result;
    }
    void generate(TreeNode* node, vector<vector<int>>& result,vector<int>& item, int sum){
        while(!node){
            return;
        }
        sum -= node->val;           //

        item.push_back(node->val);  //不管怎么样，先push_back到item里面，如果不行，后面回溯会执行pop_back

        if(sum==0 && !node->left && !node->right){      //什么时候push_back到result里面
            result.push_back(item);
        }

        generate(node->left,result,item, sum);      //递归
        generate(node->right,result,item, sum);     //递归

        sum += node->val;       //回溯
        item.pop_back();        //回溯
    }
};