/*
    92. 反转链表 II
    难度：中等
    反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
说明:
    1 ≤ m ≤ n ≤ 链表长度。

示例:
    输入: 1->2->3->4->5->NULL, m = 2, n = 4
    输出: 1->4->3->2->5->NULL
*/

//解法
/*
    请使用一趟扫描完成反转。
    链表题目 善用哑结点
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

//自己写的，我真牛逼。。。
//主要是四个结点从前往后分别是， pre_node m_head  m_tail  post_node
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(-1);
        ListNode* pre_node = new ListNode(-1);
        ListNode* m_tail = new ListNode(-1);
        dummy->next = head;
        ListNode* head_pre = dummy;
        while(n--){             //while循环这里要仔细
            if(m){
                m--;
                pre_node = dummy;
            }
            dummy = dummy->next;
            m_tail = dummy;
        }
        ListNode* m_head = pre_node->next;
        ListNode* post_node = m_tail->next;

        ListNode* p = m_head;
        ListNode* q = m_head->next;
        while(q!=post_node){
           ListNode* t = q->next;
           q->next = p;
           p = q;
           q = t;
        }

        pre_node->next = m_tail;
        m_head->next = post_node;
        return head_pre->next;          //一定要是head_pre->next;而不是head,因为head也可以会变的
    }
};
