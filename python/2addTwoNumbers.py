# -*- coding: utf-8 -*-
"""
    给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
    输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
    输出：7 -> 0 -> 8
    原因：342 + 465 = 807
"""

# Definition for singly-linked list.定义链表
class ListNode:
    def __init__ (self, value = None, next = None):
        self.val = value
        self.next = next

    def getValue(self):
        return self.val

    def getNext(self):
        return self.next

    def setValue(self,new_value):
        self.val = new_value

    def setNext(self,new_next):
        self.next = new_next


class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        re = ListNode(0)
        r=re
        carry=0
        while(l1 or l2):
            x= l1.val if l1 else 0
            y= l2.val if l2 else 0
            s=carry+x+y
            carry=s//10
            r.next=ListNode(s%10)
            r=r.next
            if(l1!=None):l1=l1.next
            if(l2!=None):l2=l2.next
        if(carry>0):
            r.next=ListNode(1)
        return re.next

l1 = ListNode(22)
l2 = ListNode(59)

al = Solution()
result = al.addTwoNumbers(l1,l2)
print(result.val)

num1_str = '299'
num1=int(num1_str[::-1]) # 取逆序
print(num1)
