#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_map>

using namespace std;

vector<int> geshi(vector<int> vec){
    if(vec[vec.size()-1]!=vec.size()) return {};
    for(auto i= vec.begin();i!=vec.end();i++){
        if(*i==90){
            i = vec.erase(i);
            i = vec.insert(i,186);
            i = vec.insert(i,91);
            i = i+2;
        }
        if(*i==91){
            i = vec.insert(i+1,187);
        }
        
    }
    return vec;
}

int main()
{
    vector<int> vec;
    int s;
    while(cin>>hex>>s){
        vec.push_back(s);
        if(cin.get()=='\n') break;
    }

    vector<int> temp;
    for(int i=1;i<vec.size()-1;i++){
        temp.push_back(vec[i]);
    }
    temp = geshi(temp);
    cout<<hex<<90<<" ";
    for(int i=0;i<temp.size();i++){
        if(temp[i]<10) cout<<0<<temp[i]<<" ";
        else cout<<hex<<temp[i]<<" ";
    }
    cout<<hex<<90<<" ";

    return 0;
}
