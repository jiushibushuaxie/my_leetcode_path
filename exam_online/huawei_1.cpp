#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_map>

using namespace std;

int main()
{
    string s;
    cin>>s;
    vector<int> vec;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9') vec.push_back(s[i]-'0');
    }
    sort(vec.begin(),vec.end());
    for(int j=0;j<vec.size();j++){
        cout<<vec[j];
    }
    //3d50J,Aa3
    return 0;
}
