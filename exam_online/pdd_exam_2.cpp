#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    int N,M;
    cin>>N>>M;
    vector<int> nums;
    for(int i=0;i!=N;i++){
        int num;
        cin>>num;
        nums.push_back(num);
    }
    int count = 0;
    for(int i=1;i<=N;i++){
       for(int j=0;(j+i)<=N;j++){
            int sum =0;
            int k = 0;
            while(k<=i-1){
                sum += nums[j+k]; 
                ++k;
            }
            if(sum%M==0)
               ++count;
        }
    }
    cout<<count<<endl;
}