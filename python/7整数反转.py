"""
    给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
    输入: 123       输入: -123      输入: 120
    输出: 321       输出: -321      输出: 21
    
    思路：对10求整，存储字符串
         判断是否溢出，反转后溢出则返回0
         由于Python的 // 操作是向下取整，导致正负数取余 % 操作结果不一致，因此需要将原数字转为正数操作。
"""
class Solution:
    def reverse(self, x):
        y = abs(x)
        result = 0
        while y:
            result = result*10 + (y%10)
            y = y//10
        result = result if x>0 else -result

        # 溢出判断
        # if result > or result < 2**31
        return result

x = -12365
solver = Solution()
result = solver.reverse(x)
print(result)

        