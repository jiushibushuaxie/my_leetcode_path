#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

ListNode* vector2list(vector<int> V){
    ListNode* head = new ListNode(-1);
    for(int i=0;i<V.size();++i){
        ListNode* temp = new ListNode(V[i]);
        head->next = temp;
    }
    return head->next;
}

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

vector<int> mergeLists(vector<vector<int>> data){
    vector<int> result=data[0];
    for(int i=1;i<data.size();++i){
        result = merge2vector(data[i],result);
    }
    return result;
}

int main(){
    int n = 0;
    cin >> n;
    
    vector<vector<int>> data;
    while(n--){
        int a;
        vector<int> item;
        while(cin>>a){
            item.push_back(a);
            if(cin.get()=='\n'){
                data.push_back(item);
                break;
            }
        }
    }

    vector<int> result = mergeLists(data);
    // output nodes 
    for(int i=0;i<result.size();++i){
        cout<<result[i]<<' ';
    }
    return 0;
}


