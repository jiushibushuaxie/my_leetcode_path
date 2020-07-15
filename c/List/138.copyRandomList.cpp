/*
    138. 复制带随机指针的链表
    难度：中等
    给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
    要求返回这个链表的 深拷贝。 
    我们用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：
    val：一个表示 Node.val 的整数。
    random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。



*/

//解法
/*
    用一个哈希表来存储random指针指向的对应关系
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node *copyRandomList(Node *head) {
    	map<Node *, int> node_map;
    	vector<Node *> node_vec;
    	Node *ptr = head;
    	int i = 0;
    	while (ptr){
	    	node_vec.push_back(new Node(ptr->val));
	    	node_map[ptr] = i;
	    	ptr = ptr->next;
	    	i++;
	    }
	    node_vec.push_back(0);
	    ptr = head;
	    i = 0;
	    while(ptr){
    		node_vec[i]->next = node_vec[i+1];
    		if (ptr->random){
    			int id = node_map[ptr->random];
		    	node_vec[i]->random = node_vec[id];
		    }
    		ptr = ptr->next;
    		i++;
    	}
    	return node_vec[0];
    }
};