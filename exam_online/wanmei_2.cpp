#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int main()
{   
    int a;
    vector<int> vec;
    while(cin>>a){
        vec.push_back(a);
        if(cin.get()=='\n') break;
    }
    if(vec.empty()) cout<<0<<endl;
    if(vec.size()==1) cout<<1<<endl;

    int result = 0;
    

    for(int i=0;i!=vec.size();i++){
        int count = 0;
        for(int j=0;j!=vec.size();j++){
            if(i==j) continue;
            if(vec[i]==vec[j]) ++count;
        }
        if(count==0) {
            result =vec[i];
            break;
        }
        
    }
    cout<<result<<endl;

    return 0;
}
