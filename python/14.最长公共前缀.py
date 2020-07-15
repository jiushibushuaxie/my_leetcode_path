# -*- coding: utf-8 -*-
"""
    编写一个函数来查找字符串数组中的最长公共前缀。
    如果不存在公共前缀，返回空字符串 ""
    所有输入只包含小写字母 a-z 
    输入: ["flower","flow","flight"]
    输出: "fl"

    思路，两两比较，得到公共前缀再跟第三个比较，直至最后一个字符串
"""
class Solution:

    def longestCommonPrefix(self, strs):
        
        if not strs :
            return ''
        if len(strs) ==  1:
            return strs[0]
        else:
            common_str = self.compare_two(strs[0],strs[1])
        for i in range(2,len(strs)):
            common_str = self.compare_two(common_str,strs[i])
        if len(common_str) == 0:
            return ""
        return common_str
        
    def compare_two(self, str1, str2):
        s_str = ''

        for i in range(min(len(str1),len(str2))):
            if str1[i] == str2[i]:
                s_str += str1[i]
            else:
                break
        return s_str


strs = ["flower","flow","flight"]

solver = Solution()
common_str = solver.longestCommonPrefix(strs)

print(common_str)