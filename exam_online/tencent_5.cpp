#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;


int main() {
    int Q;
    cin>>Q;
    long x,k;
    for(int i =0;i<Q;i++){
        cin>>x>>k;
        int count = 0;
        long temp =x;
        while(temp) {
            temp  = temp/2;
            count++;
        }

        for(int j =0; j<count-k;j++){
            x  = x /2;
        }

        if(count<=k) cout<<-1<<endl;
        else  cout<<x<<endl;

    }
}