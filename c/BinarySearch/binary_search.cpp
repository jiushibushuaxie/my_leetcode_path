/*
    循环形式二分查找
*/

#include <iostream>
#include <vector>

using namespace std;

bool binary_search(vector<int>& sort_array,int target){
    int left = 0;
    int right = sort_array.size() -1;
    while(left<=right){             // 注意这里是小于等于,退出条件肯定是left>right
        int mid = left + (right-left)/2;
        if(target == sort_array[mid]){
            return true;
        }
        else if(target<sort_array[mid]){
            right = mid-1;          //right = mid-1;
        }
        else{
            left = mid +1;          //left = mid +1; 
        }
    }
    return false;
}
