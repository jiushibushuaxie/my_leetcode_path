/*
    19. 删除链表的倒数第N个节点
    难度：中等
    给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：
    给定一个链表: 1->2->3->4->5, 和 n = 2.
    当删除了倒数第二个节点后，链表变为 1->2->3->5.

    你能尝试使用一趟扫描实现吗？
*/

//解法
/*
    你能尝试使用一趟扫描实现吗？
    快慢指针
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = new ListNode(0);
        slow->next = head;
        ListNode* res = slow;       //注意一定要用res表示head前一个结点，用于最后返回，因为head也可能被删除掉
        while(n--){
            fast = fast->next;      
        }
        while(fast){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        delete slow;
        return res->next;           //不能直接返回head，因为head也可能被删除掉
    }
};