/*
    二叉查找（排序）树的基本操作
    
    1、节点的插入
    2、查找val
        递归
*/

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

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

//查找某个val
bool BST_search(TreeNode* root, int val){
    if(root->val == val){                   //找到了节点
        return true;
    }
    if(val<root->val){                      //val 小于root->val 
        if(root->left){                     //root节点有左子节点
            return BST_search(root->left,val);         //递归
        }   
        else{                               //root节点没有左子节点
            return false;      
        }
    }
    else{                         
        if(root->right){                    //root节点有右子节点
           return BST_search(root->right,val);       //递归
        }   
        else{                               //root节点没有右子节点
            return false; 
        }
    }
}
