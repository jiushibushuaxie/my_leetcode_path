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

vector<int> max_sub(vector<int> vec, int index){
    int sum1 = 0;
    int sum = 0;
    int sum2 = 0;
    for(int j:vec) sum+=j;
    for(int i=0;i<index+1;++i)  sum1+=vec[i];
    sum2 = sum-sum1;
    vector<int> res;
    if(sum1>sum2){
        for(int k=0;k<index+1;k++) res.push_back(vec[k]);
    }
    else{
        for(int k=index+1;k<vec.size();k++) res.push_back(vec[k]);
    }
    
    return res;
}

vector<int> min_sub(vector<int> vec, int index){
    int sum1 = 0;
    int sum = 0;
    int sum2 = 0;
    for(int j:vec) sum+=j;
    for(int i=0;i<index+1;++i) sum1 +=vec[i];
    sum2 = sum-sum1;
    vector<int> res;
    if(sum1>sum2){
        for(int k=index+1;k<vec.size();k++) res.push_back(vec[k]);
    }
    else{
        for(int k=0;k<index+1;k++) res.push_back(vec[k]);
    }
    return res;
}

vector<int> max_vec(vector<int> vec1, vector<int> vec2){
    int sum1 = 0;
    int sum2 = 0;
    for(int i:vec1) sum1+=i;
    for(int j:vec2) sum2+=j;
    if(sum1>sum2) return vec1;
    else return vec2;
}

vector<int> min_vec(vector<int> vec1, vector<int> vec2){
    int sum1 = 0;
    int sum2 = 0;
    for(int i:vec1) sum1+=i;
    for(int j:vec2) sum2+=j;
    if(sum1>sum2) return vec2;
    else return vec1;
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
    vector<int> k_index(k-1,0);
    vector<int> sum_max = vec;
    vector<int> temp_vec = vec;
    vector<int> sum_min;
    k_index[0] = split_two(sum_max);
    //cout<<k_index[0]<<endl;
    sum_max = max_sub(temp_vec,k_index[0]);
    sum_min = min_sub(temp_vec,k_index[0]);
    int index = 0;
    // cout<<123<<endl;
    for(int j=1;j<k-1;j++){
        index = split_two(sum_max);
        k_index[j] =index+1 + k_index[j-1];
        //cout<<k_index[j]<<endl;
        sum_max = max_vec(max_sub(sum_max,index+1),sum_min);
        sum_min = min_vec(sum_max,sum_min);
    }
    int r=0;
    for(int i=0;i<m;i++){
        
        cout<<vec[i]<<" ";
        if(i==k_index[r]&&k_index[r]) { cout<<'/'<<" "; r++;}
       
    }
    



    return 0;
}
