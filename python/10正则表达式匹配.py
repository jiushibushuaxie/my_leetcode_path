# -*- coding: utf-8 -*-
"""
    '.' 匹配任意单个字符
    '*' 匹配零个或多个前面的那一个元素

    输入:
    s = "aa"
    p = "a"
    输出: false
    解释: "a" 无法匹配 "aa" 整个字符串。

    输入:
    s = "aa"
    p = "a*"
    输出: true

    输入:
    s = "ab"
    p = ".*"
    输出: true

    输入:
    s = "aab"
    p = "c*a*b"
    输出: true
    解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。


"""
# 动态规划

#DP Solution from @cwl
# class Solution(object):
#     def isMatch(self, s, p):
#         # The DP table and the string s and p use the same indexes i and j, but
#         # table[i][j] means the match status between p[:i] and s[:j], i.e.
#         # table[0][0] means the match status of two empty strings, and
#         # table[1][1] means the match status of p[0] and s[0]. Therefore, when
#         # refering to the i-th and the j-th characters of p and s for updating
#         # table[i][j], we use p[i - 1] and s[j - 1].
#
#         # Initialize the table with False. The first row is satisfied.
#         table = [[False] * (len(s) + 1) for _ in range(len(p) + 1)]
#
#         # Update the corner case of matching two empty strings.
#         table[0][0] = True
#
#         # Update the corner case of when s is an empty string but p is not.
#         # Since each '*' can eliminate the charter before it, the table is
#         # vertically updated by the one before previous. [test_symbol_0]
#         for i in range(2, len(p) + 1):
#             table[i][0] = table[i - 2][0] and p[i - 1] == '*'
#
#         for i in range(1, len(p) + 1):
#             for j in range(1, len(s) + 1):
#                 if p[i - 1] != "*":
#                     # Update the table by referring the diagonal element.
#                     table[i][j] = table[i - 1][j - 1] and \
#                                   (p[i - 1] == s[j - 1] or p[i - 1] == '.')
#                 else:
#                     # Eliminations (referring to the vertical element)
#                     # Either refer to the one before previous or the previous.
#                     # I.e. * eliminate the previous or count the previous.
#                     # [test_symbol_1]
#                     table[i][j] = table[i - 2][j] or table[i - 1][j]
#
#                     # Propagations (referring to the horizontal element)
#                     # If p's previous one is equal to the current s, with
#                     # helps of *, the status can be propagated from the left.
#                     # [test_symbol_2]
#                     if p[i - 2] == s[j - 1] or p[i - 2] == '.':
#                         table[i][j] |= table[i][j - 1]
#
#         return table[-1][-1]


class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        #if not s or not p:
            #return False
        s_len = len(s)
        p_len = len(p)
        dp = [[False] * (p_len + 1) for _ in range(s_len + 1)]
        #print(dp)
        dp[0][0] = True
        for i in range(p_len):
            if p[i] == "*" and dp[0][i - 1]:
                dp[0][i + 1] = True
        #print(dp)
        for i in range(s_len):
            for j in range(p_len):
                if p[j] == s[i] or p[j] == ".":
                    dp[i + 1][j + 1] = dp[i][j]
                elif p[j] == "*":
                    if p[j - 1] != s[i]:
                        dp[i + 1][j + 1] = dp[i + 1][j - 1]
                    if p[j-1] == s[i] or p[j-1] == ".":
                        dp[i+1][j+1] = (dp[i][j+1] or dp[i+1][j] or dp[i+1][j-1])
        #print(dp)
        return dp[-1][-1]

s = 'aab'
p = 'c*a*b'
slover = Solution()
print(slover.isMatch(s, p))

