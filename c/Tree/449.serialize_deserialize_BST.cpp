/*
    449. 序列化和反序列化二叉搜索树
    难度：中等

    序列化是将数据结构或对象转换为一系列位的过程，以便它可以存储在文件或内存缓冲区中，
    或通过网络连接链路传输，以便稍后在同一个或另一个计算机环境中重建。

    设计一个算法来序列化和反序列化二叉搜索树。 
    对序列化/反序列化算法的工作方式没有限制。
    您只需确保二叉搜索树可以序列化为字符串，并且可以将该字符串反序列化为最初的二叉搜索树。
    编码的字符串应尽可能紧凑。

    注意：不要使用类成员/全局/静态变量来存储状态。 你的序列化和反序列化算法应该是无状态的。

*/

/*
    考察二叉搜索树的遍历与复原
    前序遍历
    前序遍历得到的结果按顺序使用BST_insert函数可以复原二叉搜索树
    中序遍历得到的结果按顺序使用BST_insert函数得到的是向右倾斜的链表

    注意：数与数之间要用#进行分隔
    示例：
              8
             / \
            3   10     
          /  \    \
         1    6    15
    序列化 ：前序遍历  8#3#1#6#10#15#
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
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = "";
        preodrer(root, result);
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0){
            return NULL;
        }
        int i=0;
        while(data[i]!='#') {i++; }
        TreeNode* res = new TreeNode(stoi(data.substr(0,i-1)));
        int j = i;
        for(i=i+1;i<data.size();++i){
            if(data[i]=='#'){
                int val = stoi(data.substr(j+1,i-1-j));
                TreeNode* insert_node = new TreeNode(val);
                BST_insert(res,insert_node);
                j = i;
            }
        }
        return res;
    }

    void preodrer(TreeNode* node, string& result){
        if(!node){
            return;
        }
        //前序遍历
        result += to_string(node->val);
        result +='#';
        preodrer(node->left, result);
        preodrer(node->right, result);
    }

    //节点的插入
    void BST_insert(TreeNode* root, TreeNode* insert_node){
        if(insert_node->val<root->val){         //insert_node->val 小于root->val 
            if(root->left){                     //root节点有左子节点
                BST_insert(root->left, insert_node);         //递归
            }   
            else{                               //root节点没有左子节点
                root->left = insert_node;       //直接插入
            }
        }
        else{                          //把等于情况放到右边   //insert_node->val 大于等于root->val
            if(root->right){                    //root节点有右子节点
                BST_insert(root->right, insert_node);         //递归
            }   
            else{                               //root节点没有右子节点
                root->right = insert_node;      //直接插入
            }
        }
    }
};


//视频方法
class Codec {
public:
    void num2str(int val,string& data)
    {
        string tmp;
        while(val)
        {
            tmp += val%10 + '0';
            val = val / 10;
        }
        for(int i=tmp.length()-1;i>=0;i--)
        {
            data += tmp[i];
        }
        data += "#" ; 

    }
    void BST_preorder(TreeNode*root,string& data)
    {
        if(!root)
        {
            return;
        }
        string str_val;
        num2str(root->val,str_val);
        data += str_val;
        BST_preorder(root->left,data);
        BST_preorder(root->right,data);
    }
    void BST_insert(TreeNode* root,TreeNode* insert_node)
    {
        if(root->val > insert_node->val)
        {
            if(root->left)
            {
                BST_insert(root->left,insert_node);
            }
            else
            {
                root->left=insert_node;
            }
        }else
        {
            if(root->right)
            {
                BST_insert(root->right,insert_node);
            }
            else
            {
                root->right=insert_node;
            }
        }
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::string data;
        BST_preorder(root,data);
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<TreeNode*> vec;
        int val=0;
        if(data.length() == 0)
        {
            return NULL;
        }
        for(int i=0;i<data.length();i++)
        {
            if(data[i] == '#')
            {
                vec.push_back(new TreeNode(val));
                val=0;
            }else
            {
                val=val*10 + data[i] - '0';
            }
        }
        for(int i=1;i<vec.size();i++)
        {
            BST_insert(vec[0],vec[i]);
        }
        return vec[0];
    }
};