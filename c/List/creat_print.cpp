#include <iostream>
#include <vector>
using namespace std;

//定义结构体
struct ListNode{
	int val;
	ListNode* next;
    ListNode(int x): val(x),next(NULL) {}
};


/*创建单链表*/
ListNode *createList(vector<int> &A)
{
    ListNode *head = new ListNode(A[0]);
    ListNode* phead=head; //不破坏头指针
    for(int i=1;i<A.size();i++){
        //新建一个结点
        ListNode* node=new ListNode(-1);
        node->val=A[i];
        node->next=NULL;

        //把链表末结点指向新建的结点
        phead->next=node;
        //更新链表末结点
        phead=node;
    }
    return head;
}

/*打印链表*/
void printList(ListNode* head)
{
    ListNode* phead=head;
    while(phead!=NULL)
    {
        cout<<phead->val<<" ";
        phead=phead->next;
    }
    cout<<"\n";
}		


int main()
{
    vector<int> A{1,2,3,4,5,6,7,8,9};
    ListNode *head = createList(A);
    printList(head);
    return 0;
}

