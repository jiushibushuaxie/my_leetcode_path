// 两个栈实现一个队列
#include<iostream>
#include <stack>
using namespace std;

class Solution{

public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.size()!=0){           //当栈2不为空时
            int tmp = stack2.top();
            stack2.pop();
            return tmp;
        }
        else{                           //当栈2 为空时
            while(stack1.size()!=0){
                int tmp = stack1.top();
                stack1.pop();
                stack2.push(tmp);
            }
        return pop();
        }
    }   

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main()
{
    
    return 0;
}
