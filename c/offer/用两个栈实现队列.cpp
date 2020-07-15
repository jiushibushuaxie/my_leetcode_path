/*

用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，
分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )
。

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        s2.push(value);
    }
    
    int deleteHead() {
        if(s1.empty()&&s2.empty()){
            return -1;
        }
        if(s1.empty()&&!s2.empty()){
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }
        if(!s1.empty()){
            int val = s1.top();
            s1.pop();
            return val;
        }
        return -1;
    }
private:
    stack<int> s1;  //存放队头，s1为空时把s2的元素push进来
    stack<int> s2;  //存放队尾数据
};