#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main()
{
    string s;
    while(cin>>s){
        stack<char> a;
        a.push('!');
        int ok = 0;
        int left = 0;
        int right = 0;
        for(int i=0;i!=s.size();i++){
            char f = s[i];
            if(f == '('){
                a.push(f);
            }
            if(f == ')'){
                if(a.top() == '('){
                    a.pop();
                    ++ok;
                }
                else
                {
                    a.push(f);
                }
            }
        }
        while(!a.empty()){
            if(a.top()=='!') break;
            if(a.top() == '('){
                ++left;
                a.pop();
            }
            if(a.top() == ')'){
                ++right;
                a.pop();
            }
        }    
        cout<<ok<<" "<<left<<" "<<right<<endl;
    }
    
    return 0;
}
