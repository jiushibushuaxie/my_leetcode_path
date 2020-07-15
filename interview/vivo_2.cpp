#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <set>

using namespace std;

vector<int> merge2vector(vector<int> item1,vector<int> item2){
    vector<int> res;
    sort(item1.begin(),item1.end());
    sort(item2.begin(),item2.end());
    int i=0,j=0;
    while(i<item1.size()&&j<item2.size()){
        if(item1[i]<item2[j]){
            res.push_back(item1[i]);
            ++i;
        }
        else {
            res.push_back(item2[j]);
            ++j;
        }
    }
    while(i<item1.size()){
        res.push_back(item1[i]);
        i++;
    }
    while(j<item2.size()){
        res.push_back(item2[j]);
        j++;
    }
    return res;
}

int main() {
    vector<int> vec1 = {1,23,5};
    vector<int> vec2 = {34,51,2};
    vector<int> result = merge2vector(vec1,vec2);
    // output nodes 
    for(int i=0;i<result.size();++i){
        cout<<result[i]<<' ';
    }
    return 0;
}