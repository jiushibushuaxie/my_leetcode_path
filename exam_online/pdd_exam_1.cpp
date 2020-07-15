#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> prices;
    long long cost_m = 0;  // 要用长整型
    for(int i=0;i!=n;i++){
        int price;
        cin>>price;
        prices.push_back(price);
    }
    sort(prices.begin(),prices.end());

    if(!n) return 0;
    if(n==1) cout<<prices[0]<<endl;
    if(n==2) cout<<prices[0]+prices[1]<<endl;

    if(n>2){
        int count = 1;
        for(int j=prices.size()-1;j>=0;++count,--j){
            if(count%3==0) continue;
            cost_m +=prices[j];
        }
        cout<<cost_m<<endl;
    }
    return 0;
}
