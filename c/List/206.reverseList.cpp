/*
    206. 反转一个单链表。
例1
    输入: 1->2->3->4->5->NULL
    输出: 5->4->3->2->1->NULL

    进阶:
    你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
*/

//解法
/*
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


 //* Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };


//迭代法 双指针
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;   //关键，要考虑head->next是否为null

        ListNode* post =  head;    //pre在前，post在后
        ListNode* pre = nullptr;
        
        while(post){
            ListNode* t = post->next;   //定义一个临时结点来存储post->next
            post->next = pre;
            pre = post;
            post = t;
        }
        return pre;
    }
};

//递归法，有点难懂  放弃
// 终止条件为head或head->next为空，并返回head。
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode* newHead = reverseList(head->next);
        head->next->next = head;        //形成了一个环
        head->next = NULL;              //断开这个环
        return newHead;
    }
};

//无返回值的链表翻转
//因为不能传引用，所以  只能修改 head指针里面的内容 val 和 next, 这句话很关键！！！
void reverse(ListNode* head){      
    if(!head||!head->next){
        return ;
    }
    ListNode* pre = NULL;       
    ListNode* post = head;   
    ListNode* last = head->next;    
    while(post){
        ListNode* tmp = post->next;
        post->next = pre;
        pre = post;
        post = tmp;
    }
    //pre才是翻转后的头指针，
    //因为不能传引用，所以  只能修改 head指针里面的内容 val 和 next, 这句话很关键！！！
    swap(head->val,pre->val);       //交换pre与head指针里的内容
    swap(head->next,pre->next);   

    //注意交换前 head->val = 1 head->next = NULL，同时 2指向head
    //交换后 head->val = 5 , head指向4，但由于2指向head , 形成了一个环（画图理解）
    //同时pre-val = 1; pre-->next = NULL
    //所以下面这一步很关键，需要解除这个环，last是翻转前的head->next；令last->next = pre;
    last->next = pre;
    return;
}

int main(){
    
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(3);     //第四、需要new 出来
    ListNode *l4 = new ListNode(4);
    ListNode *l5 = new ListNode(5);
    
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = NULL;

    reverse(l1);
    while(l1){
        cout<<l1->val<<endl;
        l1 = l1->next;
    }
    return 0;
}

//简单暴力法，vector存链表值
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        vector<int> vec;
        if(!head) return nullptr;
        while(head){
            vec.push_back(head->val);
            head = head->next;
        }

        ListNode* head2 = new ListNode(vec[vec.size()-1]);
        ListNode* phead=head2; //不破坏头指针
        //链表的建立
        for(int i=vec.size()-2;i!=-1;--i){
            ListNode *p = new ListNode(-1);
            p->val = vec[i];
            p->next = nullptr;
            phead->next = p;
            phead = p;
        }
        return head2;
    }
};

//无返回值的链表翻转
void reverse(ListNode* head){
    if(!head||!head->next){
        return ;
    }
    ListNode* pre = NULL;
    while(head){
        ListNode* tmp = head->next;
        head->next = pre;
        pre = head;
        head = tmp;
    }
    return;
}
