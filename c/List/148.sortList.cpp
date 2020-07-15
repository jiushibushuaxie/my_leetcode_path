/*
    148. 排序链表
    难度：中等
    在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

示例1: 
    输入: 4->2->1->3
    输出: 1->2->3->4
示例2: 
    输入: -1->5->3->4->0
    输出: -1->0->3->4->5
*/

/*
    链表排序问题
    简单的冒泡排序？o(n^2)时间复杂度
    归并排序，快慢指针找到中点，切割链表
    说实话，这题有点难
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
    ListNode(int x): val(x), next(NULL){}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next){         //递归结束条件，如果没有结点/只有一个结点，无需排序，直接返回
            return head;
        }
        ListNode* fast = head->next;      //这里要注意！确保slow为中点前一节点，便于分割
        ListNode* slow = head;
        
        while(fast&&fast->next){
            fast = fast->next->next;
            slow = slow->next;          
        }

        ListNode *mid = slow->next;
        slow->next = nullptr;  //从中间断开
        //进行递归切割链表  至递归结束条件
        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);
        return(mergeList(left,right));
    }

//下面是要merge两个链表，参考21题
private:
    ListNode* mergeList(ListNode* left,ListNode* right){
        ListNode* workNode = new ListNode(0);
        ListNode* result = workNode;
        while(left && right){
            if(left->val < right->val){
                workNode->next = left;
                left = left->next;
                workNode = workNode->next;

            }
            else{
                workNode->next = right;
                right = right->next;
                workNode = workNode->next;
            }
        }
        if(!left){
            workNode->next = right;
        }
        if(!right){
            workNode->next = left;
        }

        return result->next;
    }
};