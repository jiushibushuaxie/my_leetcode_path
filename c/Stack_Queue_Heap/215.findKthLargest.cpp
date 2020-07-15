/*
    215. 数组中的第K个最大元素
    难度:中等
    在未排序的数组中找到第 k 个最大的元素。
    请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:
    输入: [3,2,1,5,6,4] 和 k = 2
    输出: 5

示例 2:
    输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
    输出: 4

*/

//解法
/*
    大顶堆，堆排序
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;    

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int ans = 0;
        for(int i=nums.size()/2-1;i>=0;--i){
            heap_adjust(nums,i,nums.size()-1);
        }
        int len = nums.size()-1;
        for(int j=0;j<k;++j){
            swap(nums,0,len);               //总是交换第一个数与结尾数。
            ans = nums[len];
            len--;
            heap_adjust(nums,0,len);        //总是调整第一个数。
        }
        return ans;
    }

    void swap(vector<int>& nums,int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        return;
    }

    void heap_adjust(vector<int>& nums,int start, int n){
        int temp = nums[start];

        for(int i=start*2+1;i<=n;i=2*i+1){
            if(i<n && nums[i]<nums[i+1]){
                i = i+1;
            }
            if(nums[start]<nums[i]){
                swap(nums,start,i);
                start = i;
            }
        }
        return;
    }
};

