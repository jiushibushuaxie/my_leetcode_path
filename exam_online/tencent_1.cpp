#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

void Push(vector<int> A, int x){
    A.push_back(x);
}

int Top(vector<int> A){
    if(A.empty()) return -1;
    int temp = A[0];
    return temp; 
}

int Pop(vector<int> &A){
    if(A.empty()) return -1;
    else A.erase(A.begin());
    return 0;
}

int Size(vector<int> A){
    return A.size();
}

void Clear(vector<int> &A){
    A.clear();
}

int main() {
    int T;
    int Q;
    cin>>T;
    while(T--){
        cin>>Q;
        string s;
        vector<int> A;
        for(int i =0;i<Q;i++){
            int num=0;
            cin>>s;
            if(s=="PUSH")  {
                cin>>num;
                A.push_back(num);
            }
            else if(s=="TOP")  cout<<Top(A)<<endl;
            else if(s=="POP")  {
                if(Pop(A)==-1){
                    cout<<-1<<endl;
                }
            }
            else if(s=="SIZE") cout<<Size(A)<<endl;
            else if(s=="CLEAR") {
                Clear(A);
            }
        }
    }
    return 0;
}