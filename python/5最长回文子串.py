# -*- coding: utf-8 -*-
"""
    给定一个字符串 s，找到 s 中最长的回文子串。
    
    输入: "babad"
    输出: "bab"
    注意: "aba" 也是一个有效答案。
"""

# 自己的解法
# class Solution(object):
#     def longestPalindrome(self, s):
#         """
#         :type s: str
#         :rtype: str
#         """


# manacher马拉车算法
def manacher(self):
    s = '#' + '#'.join(self) + '#'  # 字符串处理，用特殊字符隔离字符串，方便处理偶数子串
    lens = len(s)
    p = [0] * lens  # p[i]表示i作中心的最长回文子串的半径，初始化p[i]  p为列表，全初始化为0
    mx = 0  # 之前最长回文子串的右边界
    id = 0  # 之前最长回文子串的中心位置
    for i in range(lens):  # 遍历字符串
        if mx > i:
            p[i] = min(mx - i, p[int(2 * id - i)])  # 由理论分析得到
        else:  # mx <= i
            p[i] = 1
        while i - p[i] >= 0 and i + p[i] < lens and s[i - p[i]] == s[i + p[i]]:  # 满足回文条件的情况下
            p[i] += 1  # 两边扩展
        if (i + p[i]) > mx:  # 新子串右边界超过了之前最长子串右边界
            mx, id = i + p[i], i  # 移动之前最长回文子串的中心位置和边界，继续向右匹配
    i_res = p.index(max(p))  # 获取最终最长子串中心位置
    s_res = s[i_res - (p[i_res] - 1):i_res + p[i_res]]  # 获取最终最长子串，带"#"
    return s_res.replace('#', ''), max(p) - 1  # 返回最长回文子串（去掉"#"）和它的长度



print(manacher('cbsasbsdacscad'))




# # 以每个i为回文串中心，遍历
# class Solution(object):
#     def longestPalindrome(self, s):
#         """
#         :type s: str
#         :rtype: str
#         """
#         left = right = 0
#         n = len(s)
#         for i in range(n - 1):
#             if 2 * (n - i) + 1 < right - left + 1:
#                 break
#             l = r = i
#             while l >= 0 and r < n and s[l] == s[r]:   # while是一个循环
#                 l -= 1
#                 r += 1
#             if r - l - 2 > right - left:
#                 left = l + 1    # while循环多加了一次，所以这里要减一次
#                 print(left)
#                 right = r - 1
#                 print(right)
#             l = i
#             r = i + 1
#             while l >= 0 and r < n and s[l] == s[r]:
#                 l -= 1
#                 r += 1
#             if r - l - 2 > right - left:
#                 left = l + 1
#                 right = r - 1
#         return s[left:right + 1]
#
# s = 'abcdcb'
# d = Solution()
# print(d.longestPalindrome(s))