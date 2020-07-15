#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

int main() {
    int N;
    cin>>N;
    stack<int> s1;
    stack<int> s2;
    string op;
    for(int i =0;i<N;i++){
        cin>>op;
        int num;
        if(op=="add"){
            cin>>num;
            s1.push(num);
        }
        if(op=="poll"){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            s2.pop();
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }
        if(op=="peek"){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            cout<<s2.top()<<endl;
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }
    }

    return 0;
}