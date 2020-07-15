#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    int N,K;
    cin>>N>>K;
    vector<int> nums;
    for(int i=0;i!=N;i++){
        int num;
        cin>>num;
        nums.push_back(num);
    }
    int sum =0;
    for(int i=0;i!=nums.size();i++){
        int lower_sum=0;
        for(int j=0; j!=nums.size(); j++){
            int temp = (nums[j]-nums[i]>0)?nums[j]-nums[i]:nums[i]-nums[j];
            sum +=temp;
        }
        lower_sum = sum<lower_sum?sum:lower_sum;
        
    }
}