# -*- coding: utf-8 -*-
# 双指针法
class Solution:

    def maxArea(self, height) -> int:
        i = 0   # 首
        j = len(height) - 1  # 尾
        maxarea = 0
        for k in range(len(height)):
            if j == i:
                break
            if height[i] <= height[j]:
                maxarea = max(maxarea, height[i]*(j-i))
                i = i + 1
            elif height[i] > height[j]:
                maxarea = max(maxarea, (j-i) * height[j])
                j = j - 1
        return maxarea

li = [1,1,1,1,1,1,1,13,2]
slover = Solution()
print(slover.maxArea(li))


