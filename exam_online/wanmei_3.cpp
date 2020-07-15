#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

int main()
{   
    int N;
    long K;
    vector<int> vec;
    cin>>N>>K;
    
    TreeNode *Root(0);
    TreeNode *node = Root;
    for(int i=0;i!=N;i++){
        if(node->val==0)
        {
            node->left->val = 0;
            node->right->val = 1;
            node = node->left;
        }
        if(node->val==1)
        {
            node->left->val = 1;
            node->right->val = 0;
            node = node->right;
        }
        
    }

    return 0;
}
