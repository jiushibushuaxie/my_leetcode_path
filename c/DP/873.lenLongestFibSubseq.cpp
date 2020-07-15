//问题描述
/*
    873.
    难度:中等
    如果序列 X_1, X_2, ..., X_n 满足下列条件，就说它是 斐波那契式 的：

    n >= 3
    对于所有 i + 2 <= n，都有 X_i + X_{i+1} = X_{i+2}

    给定一个严格递增的正整数数组形成序列，找到 A 中最长的斐波那契式的子序列的长度。如果一个不存在，返回  0 。

示例1:
    输入: [1,2,3,4,5,6,7,8]
    输出: 5
    解释:
    最长的斐波那契式子序列为：[1,2,3,5,8] 。

示例 2：
    输入: [1,3,7,11,12,14,18]
    输出: 3
    解释:
    最长的斐波那契式子序列有：
    [1,11,12]，[3,11,14] 以及 [7,11,18] 。

*/

//解法
/*
    解法1：暴力
    解法2：动态规划  可转换为第300题最长上升子序列
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

//暴力法 超时
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int length = A.size();
        if(length==0) return 0;
        int ans = 0;
        for(int i=0;i<length;i++){
            for(int j=i+1;j<length;++j){
                int res = 2;
                int x = A[i]; 
                int y = A[j];
                for(int k=j+1; k<length;++k){
                    if(A[k]==x+y) {
                        ++res;
                        x = y;
                        y = A[k];
                    }
                    if(ans<res&&res>2) ans =res;
                }
            }
        }
        return ans;
    }
};

//动态规划

int main()
{
    vector<int> A = {1,2,3,4,5,6,7,8};
    Solution solver;
    int ans = solver.lenLongestFibSubseq(A);
    cout<<ans<<endl;
    return 0;
}
