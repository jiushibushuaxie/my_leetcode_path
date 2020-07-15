/*
    二叉树遍历  相当于二叉树打印
    1、二叉树的递归遍历   前序、中序、后序、层序
    2、二叉树的非递归遍历 利用迭代 前中后序用栈来实现（注意栈是先进后出，DFS深度优先）   层序是用队列来实现（BFS 宽度优先）
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//递归 前序遍历 放入数组中
vector<int> results;
void traverse(TreeNode* node){
    if(node==NULL) return;
    results.push_back(node->val);
    traverse(node->left);
    traverse(node->right);
}

vector<int> inorderTraversal(TreeNode* root) {
    traverse(root);
    return results;
}

//递归 中序遍历 放入数组中
vector<int> results;
void traverse(TreeNode* node){
    if(node==NULL) return;
    traverse(node->left);
    results.push_back(node->val);
    traverse(node->right);
}

vector<int> inorderTraversal(TreeNode* root) {
    traverse(root);
    return results;
}
//递归 后序遍历 放入数组中
vector<int> results;
void traverse(TreeNode* node){
    if(node==NULL) return;
    traverse(node->left);
    traverse(node->right);
    results.push_back(node->val);
}

vector<int> inorderTraversal(TreeNode* root) {
    traverse(root);
    return results;
}




//迭代 前序遍历 放入数组中
/*
栈S;
p= root;
while(p || S不空){
    while(p){
        访问p节点；
        p的右子树入S;
        p = p的左子树;
    }
    p = S栈顶弹出;
}
*/
vector<int> preorderTraversal(TreeNode* root) {
    stack<TreeNode*> S;
    vector<int> v;
    TreeNode* node = root;
    while(node || S.size()){
        while(node){
            S.push(node->right);
            v.push_back(node->val);
            node=node->left;
        }
        node=S.top();
        S.pop();
    }
    return v;        
}

//迭代 中序遍历 放入数组中
/* 
栈S;
p= root;
while(p || S不空){
    while(p){
        p入S;
        p = p的左子树;
    }
    p = S.top 出栈;
    访问p;
    p = p的右子树;
}
*/
vector<int> inorderTraversal(TreeNode* root) {
    stack<TreeNode*> S;
    vector<int> v;
    TreeNode* node = root;
    while(node || S.size()){
        while(node){                //先把左子树结点全入栈
            S.push(node);
            node=node->left;
        }
        node=S.top();               //访问左节点
        S.pop();                    //访问本身
        v.push_back(node->val);     
        node=node->right;           //访问右节点
    }
    return v;        
}



//迭代 后序遍历 放入数组中
/* 第一种方法
栈S;
p= root;
while(p || S不空){
    while(p){
        访问p节点；
        p的左子树入S;
        p = p的右子树;
    }
    p = S栈顶弹出;
}
结果序列逆序;
*/
vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> S;
        vector<int> v;
        TreeNode* node = root;
        while(node || S.size()){
            while(node){
                S.push(node->left);
                v.push_back(node->val);
                node=node->right;
            }
            node=S.top();
            S.pop();
        }
        reverse(v.begin(),v.end());
        return v;
}

/* 第二种方法
栈S;
p= root;
T<节点,True/False> : 节点标记;
while(p || S不空){
    while(p){
        p入S;
        p = p的左子树;
    }
    while(S不空 且 T[S.top] = True){
        访问S.top;
        S.top出S;
    }
    if(S不空){
        p = S.top 的右子树;
        T[S.top] = True;
    }
}
*/
vector<int> postorderTraversal(TreeNode* root) {
    stack<TreeNode*> S;
    unordered_map<TreeNode*,int> done;
    vector<int> v;
    TreeNode* node = root;
    while(node || S.size()){
        while(node){
            S.push(node);
            node=node->left;
        }
        while(S.size() && done[S.top()]){
            v.push_back(S.top()->val);
            S.pop();
        }
        if(S.size()){
            node=S.top()->right;
            done[S.top()]=1;    
        }
    }
    return v;
}


//层序遍历
vector<int> levelTraversal(TreeNode* root) {
    queue<TreeNode *> q;
    vector<int> v;
    q.push(root);

    while(!q.empty()){
        TreeNode* tmp = q.front();
        q.pop();

        v.push_back(tmp->val);
        if(tmp->left){
            q.push(tmp->left);
        }
        if(tmp->right){
            q.push(tmp->right);
        }
    }
}
