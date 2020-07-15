#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_map>

using namespace std;

int split_two(vector<int> vec){
    int sum1 = 0;
    int sum2 = 0;
    int sum = 0;
    int split_index = 0;
    for(int j:vec) sum+=j;

    for(int i=0;i<vec.size();++i){
        sum1 +=vec[i];
        sum2 = sum-sum1;
        if(min(sum1,sum2)>min(sum1-vec[i],sum2+vec[i])) split_index = i;
    }
    return split_index;
}


int main()
{
    int m,k;  //m个整数，划分为k个子序列
    cin>>m>>k;
    vector<int> vec(m);
    int temp;
    for(int i=0;i<m;i++){
        cin>>temp;
        vec[i] =temp;
    }
    int k_index = split_two(vec);
    for(int j=0;j<k_index+1;++j){
        cout<<vec[j]<<" ";
    }
    cout<<'/'<<" ";
    for(int j=k_index+1;j<vec.size()-1;++j){
        cout<<vec[j]<<" ";
    }
    cout<<vec[vec.size()-1];
}