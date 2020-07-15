// 类
class A
{
private:
    const int a;                // 常对象成员，只能在初始化列表赋值

public:
    // 构造函数
    A() : a(0) { };
    A(int x) : a(x) { };        // 初始化列表

    // const可用于对重载函数的区分
    int getValue();             // 普通成员函数
    int getValue() const;       // 常成员函数，不得修改类中的任何数据成员的值
};

void function()
{
    // 对象
    A b;                        // 普通对象，可以调用全部成员函数、更新常成员变量
    const A a;                  // 常对象，只能调用常成员函数
    const A *p = &a;            // 常指针
    const A &q = a;             // 常引用

    // 指针
    char greeting[] = "Hello";
    char* p1 = greeting;                // 指针变量，指向字符数组变量
    const char* p2 = greeting;          // 指针变量，指向字符数组常量
    char* const p3 = greeting;          // 常指针，指向字符数组变量
    const char* const p4 = greeting;    // 常指针，指向字符数组常量
}

// 函数
void function1(const int Var);           // 传递过来的参数在函数内不可变
void function2(const char* Var);         // 参数指针所指内容为常量
void function3(char* const Var);         // 参数指针为常指针
void function4(const int& Var);          // 引用参数在函数内为常量

// 函数返回值
const int function5();      // 返回一个常数
const int* function6();     // 返回一个指向常量的指针变量，使用：const int *p = function6();
int* const function7();     // 返回一个指向变量的常指针，使用：int* const p = function7();


#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//无返回值的链表翻转
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
    ListNode *l3 = new ListNode(3);     //第三、需要new 出来
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

