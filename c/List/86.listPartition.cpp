/*
    86. 分隔链表
    难度：中等
    给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
    你应当保留两个分区中每个节点的初始相对位置。

示例:
    输入: head = 1->4->3->2->5->2, x = 3
    输出: 1->2->2->4->3->5
*/

//解法
/*
     链表题目 善用  哑结点
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* less_head = new ListNode(0);
        ListNode* more_head = new ListNode(0);
        ListNode* less_node = less_head;
        ListNode* more_node = more_head;
        while(head){
            if(head->val<x){
                less_node->next = head;
                less_node = less_node->next;
            }
            else{
                more_node->next = head;
                more_node = more_node->next;
            }
            head = head->next;
        }
        less_node->next = more_head->next;
        more_node->next = NULL;
        return less_head->next;
    }
};