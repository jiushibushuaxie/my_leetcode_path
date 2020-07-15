/*
    拉链法解决哈希冲突
    链表头插法
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

int hash_func(int key, int table_len){
    return key%table_len;
}

void insert(ListNode* hash_table[], ListNode* node,int table_len){
    int hash_key = hash_func(node->val, table_len);
    node->next = hash_table[hash_key];      //头插法，插入到头部           
    hash_table[hash_key] = node;
}

bool search(ListNode* hash_table[],int val,int table_len){
    int hash_key = hash_func(val, table_len);
    ListNode* head = hash_table[hash_key];
    while(head){
        if(head->val==val){
            return true;
        }
        head = head->next;
    }
    return false;
}

