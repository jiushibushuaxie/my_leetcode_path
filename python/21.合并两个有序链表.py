"""
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

"""

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def mergeTwoLists(self, l1, l2):
        dummy = ListNode(0)
        p = dummy
        while l1 or l2:
            if l1 and l2:
                tmp1 = l1.val
                tmp2 = l2.val
                if tmp1 < tmp2:
                    p.next = ListNode(tmp1)
                    l1 = l1.next
                else:
                    p.next = ListNode(tmp2)
                    l2 = l2.next
            elif l1:
                p.next = ListNode(l1.val)
                l1 = l1.next
            elif l2:
                p.next = ListNode(l2.val)
                l2 = l2.next
            p = p.next
        return dummy.next
