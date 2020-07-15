#include <iostream>
#include <vector>
#include <map>
using namespace std;


// 2对1~N一共N个数，初始时各自有一个集合，对这些集合可以采取如下几种操作：
// - （1）如果x,y不在一个集合里，则将x和y所在的集合合并
// - （2）如果x所在集合中除了x还有别的数字，则将x提出单独成立一个集合
// - （3）输出x所在集合的元素个数 


struct node
{
    int value;
    node* pre;
    node* next;
    node(int v):value(v), pre(nullptr), next(nullptr){}; //构造函数
};
 
 
int main()
{
    int t;
    while(cin>>t)
    {
        while(t)
        {
        int n, m;
        cin>>n>>m;
        map<int, node*> mymap;
        for(int i=1; i<=n; i++)
        {
            node* tmp = new node(i);
            tmp->pre = tmp;
            tmp->next = tmp;
            mymap[i] = tmp;
        }
         
        int op, x, y;
        while(m)
        {
            cin>>op;
            switch(op)
            {
                case 1:
                {
                    cin>>x>>y;
                    node* temp = mymap[x]->next;
                    while(temp != mymap[x])
                    {
                        if(temp->value == mymap[y]->value)
                        {
                            break;
                        }
                        temp = temp->next;
                    }
                    if(temp == mymap[x])
                    {
                        node* prex = mymap[x]->pre;
                        node* prey = mymap[y]->pre;
                        prex->next = mymap[y];
                        mymap[y]->pre = prex;
                        prey->next = mymap[x];
                        mymap[x]->pre = prey;
                    }
                     
                    break;
                }
                case 2:
                {
                    cin>>x;
                    if(mymap[x]->next != mymap[x])
                    {
                        node* temp = mymap[x]->pre;
                        temp->next = mymap[x]->next;
                        mymap[x]->next->pre = temp;
                        mymap[x]->pre = mymap[x];
                        mymap[x]->next = mymap[x];
                    }
                    break;
                }
                case 3:
                {
                    cin>>x;
                    node* temp = mymap[x]->next;
                    int res = 1;
                    while(temp != mymap[x])
                    {
                        res++;
                        temp = temp->next;
                    }
                    cout<<res<<endl;
                    break;
                }
                default:
                    break;
            }
            m--;
        }
        t--;
    }
    }
    return 0;
}