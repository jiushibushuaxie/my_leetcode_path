/*
    234. 回文链表
    难度:简单
    请判断一个链表是否为回文链表。

示例
    输入: 1->2
    输出: false

    输入: 1->2->2->1
    输出: true

你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
*/

/*
    要求O(1) 空间复杂度
    快慢指针
    用快慢指针遍历的同时翻转前半部分，然后与后半部分比较即可。巧妙

    若不要求空间复杂度，讲数值入栈进行判断
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next){
            return true;
        }
        ListNode* fast = head;
        ListNode* slow = head;

        ListNode* pre = NULL;
        ListNode* post = head;

        while(fast&&fast->next){
            //快慢指针
            fast = fast->next->next;
            slow = slow->next;

            //翻转链表
            ListNode* temp = post->next;
            post->next = pre;
            pre = post;
            post = temp; 
        }

        if(fast){               //奇数个节点时跳过中间节点
            slow = slow->next;
        }

        while(pre&&slow){               //注意这里是pre,pre指向翻转后的头结点
            if(pre->val!=slow->val){
                return false;
            }
            pre = pre->next;
            slow = slow->next;
        }
        return true;
    }
};