/*
    递归形式二分查找
*/

#include <iostream>
#include <vector>

using namespace std;

bool binary_search(vector<int>& sort_array,
                   int left, int right, int target){
    
    if(left>right) return false ; //递归结束条件
    
    int mid = left + (right-left)/2;
    if(target == sort_array[mid]){
        return true;
    }
    else if(target<sort_array[mid]){
        return binary_search(sort_array,left,mid-1,target);
    }
    else{
        return binary_search(sort_array,mid+1,right,target);
    }
}
