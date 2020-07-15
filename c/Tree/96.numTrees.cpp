/*
    96. 不同的二叉搜索树
    难度:中等
    给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？

示例:
    输入: 3
    输出: 5
    解释:
    给定 n = 3, 一共有 5 种不同结构的二叉搜索树:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

*/

//解法
/*
    第一感觉像是一个数学题。数学统计归纳也可以
    但其实是个动态规划题。注意是二叉搜索树
    假设n个节点存在二叉排序树的个数是G(n);
    令f(i)为以i为根的二叉搜索树的个数;
    即有:G(n) = f(1) + f(2) + f(3) + f(4) + ... + f(n);
    n为根节点，当i为根节点时，其左子树节点个数为[1,2,3,...,i-1]，右子树节点个数为[i+1,i+2,...n];
    所以当i为根节点时，其左子树节点个数为i-1个，右子树节点为n-i，即f(i) = G(i-1)*G(n-i),
    上面两式可得:G(n) = G(0)*G(n-1)+G(1)*G(n-2)+...+G(n-1)*G(0)
    1、子问题  i个结点的搜索树数目dp[i]
    2、边界条件  dp[0] =1, dp[1] = 1;
    3、状态转移方程 dp[i] = dp[0]*dp[i-1] + dp[1]*dp[i-2] +... +dp[i-1]*dp[0]; 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x),left(NULL), right(NULL){}
};

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;

        for(int i=2;i<n+1;++i){
            for(int j=0;j<i;++j){
                dp[i] += dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
};