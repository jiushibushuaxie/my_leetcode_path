/*
    31. 下一个排列
    难度：中等
    实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
    如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
    必须原地修改，只允许使用额外常数空间。

    以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
    1,2,3 → 1,3,2
    3,2,1 → 1,2,3
    1,1,5 → 1,5,1
*/

//解法
/*
    注意是字典序
    从后往前  
    （1）先找到第一个升序组的第一个数字 A[i]>A[j]
    （2）再找到 j之后第一个大于A[i]的数字A[k]，交换A[i]与A[k]
    （3）最后讲j到end的数字进行逆序
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==1||!nums.size()) return;
        int A_i = 0;   
        int A_j = 0;
        int index_i = 0;
        int index_j = 0;
        int index_k = 0;
        bool flag = true;
        //（1）
        for(int i=nums.size()-1;i>0;--i){
            A_i = nums[i-1];
            A_j = nums[i];
            index_i = i-1;
            index_j = i;
            if(A_i < A_j ){
                flag = false;
                break;
            }
        }
        if(flag){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int j=nums.size()-1;j>=index_j;--j){
            if(nums[j]>A_i){
                index_k = j; 
                break;
            }
        }
        //(2)
        swap(nums,index_i,index_k);
        //（3）
        int left = index_j;
        int right = nums.size()-1;
        while(left<right){
            swap(nums,left,right);
            left++;
            right--;
        }
        return;
    }
    void swap(vector<int>& nums,int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        return;
    }
};

int main(){
    vector<int> nums = {1,1};
    Solution solver;
    solver.nextPermutation(nums);
    return 0;
}
