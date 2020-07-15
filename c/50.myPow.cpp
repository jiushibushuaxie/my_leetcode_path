/*
    50. Pow(x, n)
    难度：中等
    实现 pow(x, n) ，即计算 x 的 n 次幂函数。
*/

//解法
/*
    快速幂
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        if(x == 1 || n == 0) return 1;
        long num = n;       //用long存储n
        if(num<0){
            x = 1/x;
            num = -num;
        }
        while(num){     
            if(num&1) {    //判断n的末尾是否为1
                ans = ans*x;
            }
            x *= x;     //这是基数
            num = num>>1;
        }
        return ans;
    }
};