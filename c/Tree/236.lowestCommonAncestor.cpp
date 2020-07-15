/*
    236. 二叉树的最近公共祖先
    难度:中等
    给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
    
    百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，
    满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
    例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]
               3
             /   \
            5     1
           / \   /  \
          6   2  0   8
             / \    
            7   4  

示例 1:
    输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
    输出: 3
    解释: 节点 5 和节点 1 的最近公共祖先是节点 3。

示例 2:
    输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
    输出: 5
    解释: 节点 5 和节点 4 的最近公共祖先是节点 5。
    根据定义最近公共祖先节点可以为节点本身。

*/

/*
    解法：前序深度搜索
    1、从根节点开始搜索结点p或q,找到p或q后就结束搜索
    2、将搜索过程中遇到的结点按照顺序存储起来
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

//解法一，路径搜索，保存路径，最后判断
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> result_p;   //找到p节点后，保存的路径
        vector<TreeNode*> path_p;     //遍历过程中节点路径
        vector<TreeNode*> result_q;   //找到q节点后，保存的路径
        vector<TreeNode*> path_q;     //遍历过程中节点路径
        int finished_p = 0;
        int finished_q = 0;
        preorder(root, p, path_p, result_p, finished_p);
        preorder(root, q, path_q, result_q, finished_q);

        int path_len = 0;  //较短路径的长度
        path_len = result_p.size()>result_q.size()?result_q.size():result_p.size();

        TreeNode* result=0;   //最后结果
        for (int i = 0; i < path_len; i++){     //找到最后相等的节点
        	if (result_p[i] == result_q[i]){
	        	result = result_p[i];
	        }
        }
        return result;
    }

    void preorder(TreeNode* node, TreeNode* search, 
                  vector<TreeNode*>& path,
                  vector<TreeNode*>& result,
                  int& finished){
        if(!node||finished){     //如果找到了，finshed=1，结束递归遍历
            return;
        }
        path.push_back(node);       ///不管怎么样，先push_back到path里面，如果不行，后面回溯会执行pop_back
        if(node==search){
            finished=1;
            result = path;
        }
        preorder(node->left, search, path, result, finished);           //递归
        preorder(node->right, search, path, result, finished);          //递归

        path.pop_back();                        //回溯,后序做的事，也就是回溯
    }
};


//解法二：简洁
/*
    对于每一个子树
（1） 如果当前结点 root 等于 NULL，则直接返回 NULL
（2） 如果 root 等于 p 或者 q ，那这棵树一定返回 p 或者 q
（3） 然后递归左右子树，因为是递归，使用函数后可认为左右子树已经算出结果，用 left 和 right表示
（4） 此时若left为空，那最终结果只要看 right；若 right 为空，那最终结果只要看 left
（5） 如果 left 和 right 都非空，因为只给了 p 和 q 两个结点，都非空，说明一边一个，因此 root 是他们的最近公共祖先
（6） 如果 left 和 right 都为空，则返回空（其实已经包含在前面的情况中了）

时间复杂度是 O(n)：每个结点最多遍历一次或用主定理，空间复杂度是 O(n)：需要系统栈空间
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)                //递归终止条件：如果当前节点为空或等于 p 或 q，则返回当前节点
            return NULL;
        if(root == p || root == q) 
            return root;
            
        TreeNode* left =  lowestCommonAncestor(root->left, p, q);    //在左子树里找
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
       
        //后序操作，从后往前，相当于回溯
        if(left == NULL)            //左子树里没找到，那么p,q都在右子树，right为最先找到的节点
            return right;
        if(right == NULL)           //右子树里没找到，那么p,q都在左子树，left为最先找到的节点
            return left;      
        if(left && right)           // p和q在两侧,返回root
            return root;
        
        return NULL; // 必须有返回值
    }
};

