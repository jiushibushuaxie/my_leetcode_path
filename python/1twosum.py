# -*- coding: utf-8 -*-
"""
    给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
    
    哈希映射，将列表下标作为value,将value作为下标，空间换时间
    给定 nums = [2, 7, 11, 15], target = 9
    因为 nums[0] + nums[1] = 2 + 7 = 9
    所以返回 [0, 1]

"""

# class Solution:
#     def twoSum(self, nums, target):
#         """
#         :type nums: List[int]
#         :type target: int
#         :rtype: List[int]
#         """
#         sorted_id = sorted(range(len(nums)), key=lambda k: nums[k])
#         head = 0
#         tail = len(nums) - 1
#         sum_result = nums[sorted_id[head]] + nums[sorted_id[tail]]
#         while sum_result != target:
#             if sum_result > target:
#                 tail -= 1
#             elif sum_result < target:
#                 head += 1
#             sum_result = nums[sorted_id[head]] + nums[sorted_id[tail]]
#         return [sorted_id[head], sorted_id[tail]]

class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        hashmap = {}
        for index, num in enumerate(nums):
            another_num = target - num
            if another_num in hashmap:  # 如果出现匹配的数字在哈希列表里，直接得出结果
                return [hashmap[another_num], index]
            hashmap[num] = index  # 存储出现过的下标
        return None

a = [1,9,5,7,8]
d = 8
result = Solution()
r = result.twoSum(a, d)
print(r)


# if in 判断的是字典里的key，而不是value
# ab = {1:2, 3:4}
# if 3 in ab:
#     print(123)
