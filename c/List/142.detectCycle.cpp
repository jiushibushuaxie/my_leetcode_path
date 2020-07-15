/*
    142. 环形链表 II
    难度：中等
    给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
    为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 
    如果 pos 是 -1，则在该链表中没有环。

    说明：不允许修改给定的链表。
示例: 
    输入：head = [3,2,0,-4], pos = 1
    输出：tail connects to node index 1
    解释：链表中有一个环，其尾部连接到第二个节点。

进阶：
    你是否可以不用额外空间解决此题？
*/

/*
    快慢指针   转好为一个简单的数学计算问题
    快指针与慢指针相等时，快指针多走一圈
    假设直线链表（非环区域）长度位a（包括入环链表点）,  慢指针走了a+b步，b为在环中走的步数
    则 a+b+x = 2a+2b ， 环长度x = a+b;
    所以再初始化一个链表指针plus指向head, 与慢指针同时走，两指针相交点即为返回值。（走了a步）
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
    ListNode *detectCycle(ListNode *head) {
        if(!head||!head->next){
            return nullptr;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while(true){
            if(fast&&fast->next){               //快指针可以走的条件 为 fast&&fast->next 存在
                fast = fast->next->next;
                slow = slow->next;
            }
            else{                               //否则，必定无环
                return nullptr;
            }
            if(fast == slow){                   //确定有环，break
                break;
            }
        }

        ListNode* plus = head;
        while(plus!=slow){
            slow = slow->next;
            plus = plus->next;
        }

        return plus;
    }
};