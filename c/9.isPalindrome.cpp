/*
    9. 回文数  
    判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

例1
    输入: 121
    输出: true
例2
    输入: -121
    输出: false
    解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
例3
    输入: 10
    输出: false
    解释: 从右向左读, 为 01 。因此它不是一个回文数。
*/

/*
   负数不可能是回文数

*/

class Solution {
public:
    bool isPalindrome(int x) {
        int y = x;
        int reverse = 0;
        if(x<0)
            return false;
        while(x){
            reverse = 10*reverse + x%10;
            x = x/10;
        }
        if(reverse == y)
            return true;
        else{
            return false;
        }
        
    }
};