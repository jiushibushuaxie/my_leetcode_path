# -*- coding: utf-8 -*-
# 第三题，无重复字符的最长字串
"""
    输入: "abcabcbb"
    输出: 3 
    解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
"""
# test
# 自己的解法
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        """
            :type s: str
            :rtype: int
        """
        temp_str = ''
        ans1 = 0
        ans2 = 0
        for i in s:
            if i in temp_str:
                print(temp_str)
                ans1 = max(ans1,len(temp_str))
                index = temp_str.index(i)
                temp_str = temp_str[index+1:] + i
            if i not in temp_str:
                print(temp_str)
                temp_str += i
                ans2 = len(temp_str)
        return max(ans1,ans2)

ss = 'abcehdabcgllfjtabcvonqw'

aa = Solution()

ans = aa.lengthOfLongestSubstring(ss)

print(ans)

# class Solution:
#     def lengthOfLongestSubstring(self, s):
#         """
#         :type s: str
#         :rtype: int
#         """
#         max_number = 0
#         number = 0
#         test = ''
#         for i in s:
#             if i not in test:
#                 test += i
#                 number += 1
#             else:
#                 if number >= max_number:
#                     max_number = number
#                 index = test.index(i)
#                 test = test[(index+1):] + i
#                 number = len(test)
#         if number > max_number:
#             max_number = number
#         return max_number
#
#
# class Solution:
#    def lengthOfLongestSubstring(self, s: str) -> int:
#        if len(s) <= 1:
#            return len(s)
#        max_len = 1
#        for i in range(len(s)):
#            for j in range(i + 1, len(s)):
#                if s[j] in s[i:j]:
#                    break
#                max_len = max(max_len, j - i + 1)
#        return max_len