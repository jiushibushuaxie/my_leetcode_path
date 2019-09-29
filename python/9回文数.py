"""
    判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。    
    输入: 121
    输出: true

    输入: -121
    输出: false
    解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
    所以负数肯定不是回文数

    注意事项：'int' object has no attribute 'copy' int不能用copy()
    暂时存储x的值
"""
class Solution:
    def isPalindrome(self, x):
        if x < 0:
            return False
        y = 0
        z = x # 暂存x的值
        while x:
            y = y*10 + x%10
            x = x//10
        if y == z:
            return True
        else:
            return False

num = 12321
solver =  Solution()
print(solver.isPalindrome(num))