//问题描述
/*
    160.相交链表  
    编写一个程序，找到两个单链表相交的起始节点。

输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
输出：Reference of the node with value = 8
输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。
从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。
在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。

注意：

    如果两个链表没有交点，返回 null.
    在返回结果后，两个链表仍须保持原有的结构。
    可假定整个链表结构中没有循环。
    程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。

//解法
/*
    长度差
    双指针
*/
#include<iostream>
#include<vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


//先遍历两个链表，得到长度，计算出长度差，然后让长链表指针先走，后面再一起走
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA||!headB) //若有结点为空，则必然无交点
            return nullptr;
        ListNode *pA = headA;  
        ListNode *pB = headB;  
        int length_A =0;       //因为这里tmd是在函数体里面！ //一定要他妈的初始化，这里花了我一个小时时间~~~~！！！！！！！！！！！！！！！！
        int length_B =0;       //因为这里tmd是在函数体里面！ //一定要他妈的初始化，这里花了我一个小时时间~~~~！！！！！！！！！！！！！！！！
        while(pA){
            ++length_A;
            pA=pA->next;
        } 
        while(pB){
            ++length_B;
            pB=pB->next;
        }
        int diff = length_A>length_B?(length_A-length_B):(length_B-length_A);
        int flag = length_A>length_B?1:0;

        pA = headA;
        pB = headB;
 
        while(diff--){
            if(flag) pA = pA->next;
            if(!flag) pB = pB->next;
        }
        
        while(pA&&pB){
            if(pA==pB) return pA;
            pA = pA->next;
            pB = pB->next;
        }
        return nullptr;
    }
};


//双指针法
//太巧妙了，a,b分别走完headA和headB的所有结点
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto a = headA, b = headB;
        while(a != b )
        {
            a = a? a->next:headB;  //如果a走完了就把a指向headB，去走headB的结点
            b = b? b->next:headA;  //如果b走完了就把b指向headA，去走headA的结点
        }
        return a;
    }
};

