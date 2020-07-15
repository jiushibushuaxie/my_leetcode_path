#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int main()
{   
    int a;
    int n;
    vector<int> vec;
    while(cin>>a){
        vec.push_back(a);
        if(cin.get()=='\n') break;
    }
    cin>>n;
    vec.erase(vec.end()-n);
    for(int i=0;i!=vec.size();i++){
        cout<<vec[i]<<" ";
    }
    return 0;
}
