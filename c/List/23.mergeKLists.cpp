/*
    23. 合并K个排序链表
    难度：困难
    合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:
    输入:
    [
    1->4->5,
    1->3->4,
    2->6
    ]
    输出: 1->1->2->3->4->4->5->6

*/

//解法
/*
    与归并排序一样
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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	ListNode temp_head(0);
    	ListNode *pre = &temp_head;
    	while (l1 && l2){
	    	if (l1->val < l2->val){
	    		pre->next = l1;
	    		l1 = l1->next;
	    	}
	    	else{
	    		pre->next = l2;
	    		l2 = l2->next;
	    	}
	    	pre = pre->next;
	    }
	    if (l1){
    		pre->next = l1;
    	}
    	if (l2){
	    	pre->next = l2;
	    }
        return temp_head.next;
    }	

    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    	if (lists.size() == 0){
        	return NULL;
        }
    	if (lists.size() == 1){
	    	return lists[0];
	    }
	    if (lists.size() == 2){
    		return mergeTwoLists(lists[0], lists[1]);
    	}
    	int mid = lists.size() / 2;
		
    	vector<ListNode*> sub1_lists;
    	vector<ListNode*> sub2_lists;
    	for (int i = 0; i < mid; i++){
	    	sub1_lists.push_back(lists[i]);
	    }
	    for (int i = mid; i < lists.size(); i++){
    		sub2_lists.push_back(lists[i]);
    	}
    	ListNode *l1 = mergeKLists(sub1_lists);
    	ListNode *l2 = mergeKLists(sub2_lists);
    	return mergeTwoLists(l1, l2);
    }
};