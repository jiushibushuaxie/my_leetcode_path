#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <set>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    vector<int> data;
    int a;
    while(cin>>a){
        data.push_back(a);
    }
    int ans = 0;
    
    for(int i=0;i<data.size();i++){
        if(i==0&&data[i]==0&&data[i+1]==0){
            ans++;
            data[i] = 1;
        }
        if(i==data.size()-1&&data[i]==0&&data[i-1]==0){
            ans++;
            data[i] = 1;
        }
        if(i>0&&data[i]==0&&i<data.size()-1&&data[i-1]==0&& data[i+1]==0){
            ans++;
            data[i]=1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
