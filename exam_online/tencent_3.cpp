#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> a(n,0);
    vector<int> b(n,0);
    for(int i =0;i<n;i++){
        int ai;
        cin>>ai;
        a[i] = ai;
    }
    for(int i =0;i<n;i++){
        int bi;
        cin>>bi;
        b[i] = bi;
    }

    int count = 0;
    for(int i =0;i<n-1;i++){
        if(a[i]>a[i+1]) {
            if(b[i]>b[i+1]) {
                count++;
                a[i] = b[i+1];
                a[i+1] = b[i];
            }
        }
        else continue;
    }
    
    if(count == 0) cout<<-1<<endl;
    else cout<<count<<endl;
        
    return 0;
}