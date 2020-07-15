/*
    543. 二叉树的直径
    难度:简单
    给定一棵二叉树，你需要计算它的直径长度。
    一棵二叉树的直径长度是任意两个结点路径长度中的最大值。
    这条路径可能穿过也可能不穿过根结点。

示例
    给定二叉树

          1
         / \
        2   3
       / \     
      4   5    
    返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。
    两结点之间的路径长度是以它们之间边的数目表示。
*/

/*
    在计算高度函数中加一行代码，维护一个最大直径的变量
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
    int diameterOfBinaryTree(TreeNode* root) {
        level(root);
        return max_diameter;
    }

    int level(TreeNode *root){ 
        if(root == nullptr) return 0;  //当结点为空时，没有高度，为0
        int left_depth = level(root->left);
        int right_depth = level(root->right);
        max_diameter = max(max_diameter, left_depth+right_depth);     //维护一个最大直径
        return max(left_depth, right_depth) + 1;                      //返回的是该节点的高度
    }
private:
    int max_diameter = 0;
};
