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

vector<int> preTravel(TreeNode *root){
    stack<TreeNode *> S;
    vector<int> vec;
    TreeNode *node = root; 
    while(node||S.size()){              //判断条件要记好，看不懂就画个二叉树跟着走
        while(node){                    //判断条件要记好
            S.push(node->right);        //前序是把右结点压入栈中
            vec.push_back(node->val);   //压入同时打印当前结点
            node = node->left;          //下个指向左子节点
        }
        node = S.top();
        S.pop();
    }
    return vec;
}

vector<int> inTravel(TreeNode *root){
    stack<TreeNode *> S;
    vector<int> vec;
    TreeNode *node = root;
    while(node||S.size()){
        while(node){
            S.push(node);           //中序是把自己结点压入栈中
            node = node->left;      //下个指向左子节点
        }
        node = S.top();
        S.pop();
        vec.push_back(node->val);   //在弹出过程中打印
        S.push(node->right);        //弹出过程中记得要指向右子节点
    }
    return vec;
}

vector<int> postTravel(TreeNode *root){
    stack<TreeNode *> S;
    vector<int> vec;
    TreeNode *node = root;
    while(node||S.size()){
        while(node){
            S.push(node->left);             //后序是把左子结点压入栈中
            vec.push_back(node->val);       //压入同时打印当前结点
            node = node->right;
        }
        node = S.top();
        S.pop();
    }
    reverse(vec.begin(),vec.end());         //不要忘记最好还要翻转
    return vec;
}

vector<int> postTravel2(TreeNode *root){
    stack<TreeNode *> S;
    vector<int> vec;
    unordered_map<TreeNode *, int> done;
    TreeNode *node = root;
    while(node||S.size()){
        while(node){
            S.push(node);
            node = node->left;
        }
        while(S.size()&&done[node]){        //判断条件要记好
            vec.push_back(S.top()->val);
            S.pop();
        }
        if(S.size()){                       //判断条件要记好
            node = S.top()->right;
            done[S.top()]=1;

        }
    }
    return vec;
}

vector<int> levelTravel(TreeNode* root) {
    queue<TreeNode *> Q;
    vector<int> vec;
    Q.push(root);           //先把头结点放入队列中
    while(!Q.empty()){
        TreeNode *node = Q.front();       //临时存储
        Q.pop();
        vec.push_back(node->val);

        if(node->left) Q.push(node->left);
        if(node->right) Q.push(node->right);
    }
    return vec;
}