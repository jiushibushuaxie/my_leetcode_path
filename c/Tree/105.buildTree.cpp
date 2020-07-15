/*
    105. 从前序与中序遍历序列构造二叉树
    难度:中等
    根据一棵树的前序遍历与中序遍历构造二叉树。

    注意:
    你可以假设树中没有重复的元素。

例如，给出
    前序遍历 preorder = [3,9,20,15,7]
    中序遍历 inorder = [9,3,15,20,7]

返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7

*/

//解法
/*
    步骤：
    1、前序中 左起第一位1肯定是根结点，我们可以据此找到中序中根结点的位置rootin；
    2、中序中 根结点左边就是左子树结点，右边就是右子树结点，即[左子树结点，根结点，右子树结点]，
        我们就可以得出左子树结点个数为int left = rootin - leftin;；
    3、前序中 结点分布应该是：[根结点，左子树结点，右子树结点]；
    4、根据前一步确定的左子树个数，可以确定前序中左子树结点和右子树结点的范围；
    5、如果我们要前序遍历生成二叉树的话，下一层递归应该是：
        左子树：root->left = pre_order(前序左子树范围，中序左子树范围，前序序列，中序序列);；
        右子树：root->right = pre_order(前序右子树范围，中序右子树范围，前序序列，中序序列);。
    6、每一层递归都要返回当前根结点root；

    有点二分的意思在里面
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x),left(NULL), right(NULL){}
};

class Solution {
private:
    unordered_map<int, int> index;

public:
    TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, 
                         int preorder_left, int preorder_right, 
                         int inorder_left, int inorder_right) {
        if (preorder_left > preorder_right) {   //递归结束条件，有点像二分结束条件
            return nullptr;
        }
        
        // 前序遍历中的第一个节点就是根节点
        int preorder_root = preorder_left;          //前序根节点下标
        // 在中序遍历中定位根节点
        int inorder_root = index[preorder[preorder_root]];  //中序根节点下标
        
        // 先把根节点建立出来
        TreeNode* root = new TreeNode(preorder[preorder_root]);
        // 得到左子树中的节点数目
        int size_left_subtree = inorder_root - inorder_left;
        // 递归地构造左子树，并连接到根节点
        // 先序遍历中「从 左边界+1 开始的 size_left_subtree」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
        root->left = myBuildTree(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
        // 递归地构造右子树，并连接到根节点
        // 先序遍历中「从 左边界+1+左子树节点数目 开始到 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
        root->right = myBuildTree(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        // 构造中序遍历的下标与值的哈希映射，帮助我们快速定位根节点
        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i;          
        }
        return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};