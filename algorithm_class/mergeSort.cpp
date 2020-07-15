#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>

using namespace std;
//归并排序  
//时间复杂度：nlogn 空间复杂度 O(n)  稳定
//给定一个int数组A及数组的大小n，请返回排序后的数组。


void merge_two_vec(const vector<int> &sub_vec1,
                   const vector<int> &sub_vec2,
                   vector<int> &vec){
    int i=0,j=0;
    while(i<sub_vec1.size() && j<sub_vec2.size()){
        if(sub_vec1[i]<=sub_vec2[j]){
            vec.push_back(sub_vec1[i]);
            ++i;
        }
        else{
            vec.push_back(sub_vec2[j]);
            ++j;
        }
    }
    //剩余的单独处理
    for(;i<sub_vec1.size();++i){
        vec.push_back(sub_vec1[i]);
    }
    for(;j<sub_vec2.size();++j){
        vec.push_back(sub_vec2[j]);
    }
}

void merge_sort(vector<int>& vec){
    if(vec.size()<2){       //递归结束条件
        return;
    }
    int mid = vec.size()/2;     //从中间分割数组
    vector<int> sub_vec1;
    vector<int> sub_vec2;
    for(int i=0;i<mid;++i){
        sub_vec1.push_back(vec[i]);
    }
    for(int i=mid;i<vec.size();++i){
        sub_vec2.push_back(vec[i]);
    }
    merge_sort(sub_vec1);       //递归
    merge_sort(sub_vec2);       //递归
    vec.clear();                //关键
    merge_two_vec(sub_vec1,sub_vec2,vec);       //分治解决
}

int main()
{
    vector<int>test_vec = {4,1,5,7,8,9,3,2,6};
    merge_sort(test_vec);
    for(int i=0;i<test_vec.size();++i){
        cout<<test_vec[i]<<'\t';
    }
    return 0;
}
