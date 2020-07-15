/*
    70.爬楼梯  
    假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
    每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
    注意：给定 n 是一个正整数。

示例 1:
    输入： 2
    输出： 2
    解释： 有两种方法可以爬到楼顶。
    1.  1 阶 + 1 阶
    2.  2 阶

示例 2：
    输入： 3
    输出： 3
    解释： 有三种方法可以爬到楼顶。
    1.  1 阶 + 1 阶 + 1 阶
    2.  1 阶 + 2 阶
    3.  2 阶 + 1 阶

*/

//解法
/*
    //动态规划
    爬i级楼梯的方法 fun[i] = fun[i-1] + fun[i-2]
    fun[1] = 1  fun[2] = 2
    只需要知道两个状态即可。

    //递归法
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

// 动态规划  动态规划是从下往上一步步爬上去 
class Solution {
public:
    int climbStairs(int n) {
        if(!n) return 0;
        int i=3;
        int fun_i_1 = 2;
        int fun_i_2 = 1;
        if(n==1) return 1;
        if(n==2) return 2;
        int fun_i = 0;
        while(i<n){
            fun_i = fun_i_1 + fun_i_2;
            fun_i_2 = fun_i_1;
            fun_i_1 = fun_i;
            ++i;
        }
         
        return fun_i;
    }
};

//递归  递归是从高往低俯冲下来的，要有终止递归条件
//时间复杂度 2^n次方
class Solution {
public:
    int climbStairs(int n) {
        if(n==1||n==2){
            return n;
        }
        return climbStairs(n-1) + climbStairs(n-2); 
    }
};

int main(int argc, const char** argv) {
    int n = 5;
    Solution solver;
    int ans= solver.climbStairs(n);
    cout<<ans<<endl;
    return 0;
}