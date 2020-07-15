/*
    二叉树重建  相当于二叉树建立， 给定一个数组,建立一个二叉树链表
    输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//方法一、 直接建立
    // Node* node1 = new Node(1);
	// Node* node2 = new Node(2);
	// Node* node3 = new Node(3);
	// Node* node4 = new Node(4);
	// Node* node5 = new Node(5);
	// Node* node6 = new Node(6);
	// Node* node7 = new Node(7);
	// Node* node8 = new Node(8);

	// node1->left = node2;
	// node1->right = node3;
	// node2->right = node4;
	// node3->left = node5;
	// node3->right = node6;
	// node4->left = node7;
	// node4->right = node8;

