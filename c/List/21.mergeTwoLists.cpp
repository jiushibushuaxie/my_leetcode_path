//问题描述
/*
    21. 合并两个有序链表 
    将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例 1:
    输入：1->2->4, 1->3->4
    输出：1->1->2->3->4->4

*/

//解法
/*
    链表需要自定义
    学会使用链表操作
*/

#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

struct ListNode {
    int val;   //数据域
    ListNode *next;  //指针域
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //l1,l2都是链表头指针
        // 定义一个新的链表
        ListNode *result= new ListNode(0); //result为头结点指针
        ListNode *workNode = result;    //一个工作结点

        //当链表l1和l2非空时
        while(l1&&l2){
            if(l1->val<=l2->val){
                workNode->next = l1;
                workNode = l1;
                l1 = l1->next;
            }
            else{
                workNode->next = l2;
                workNode = l2;
                l2 = l2->next;
            }
        }
        if(!l1)
            workNode->next = l2;
        if(!l2)
            workNode->next = l1;
        return result->next;  
    }
};