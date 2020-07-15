//问题描述
/*
    7.整数反转  
    给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

例1
    输入: 123
    输出: 321
例2
    输入: -123
    输出: -321
例3
    输入: 120
    输出: 21
*/

//解法
/*
   考虑情况要全面
   考虑溢出的情况，负号情况不用考虑
   
   判断条件为商是否为0；

*/

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int reverse(int x) {
        int result=0;
        while(x){
            if(result > INT_MAX/10 || result < INT_MIN/10) //溢出  判断result是否溢出
                return 0;
            result = 10*result+x%10;
            x = x/10;

        }
        return result;
    }
};


int main(int argc, const char** argv) {
    int test = 123;
    Solution solver;
    int ans= solver.reverse(test);
    cout<<ans<<endl;
    return 0;
}