/*
    581. 最短无序连续子数组
    难度:简单
    给定一个整数数组，你需要寻找一个连续的子数组，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。

    你找到的子数组应是最短的，请输出它的长度。
示例
    输入: [2, 6, 4, 8, 10, 9, 15]
    输出: 5
    解释: 你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。

    输入的数组可能包含重复元素 ，所以升序的意思是<=。
*/

/*
   创建一个数组保存排序后的nums数组，分别找到第一个和最后一个同下标却不同值的元素，
   两个下标的差-1就是最短子数组长度。
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> v(nums);
        sort(v.begin(),v.end());
        int start=0;
        int end=nums.size()-1;

        while(start<end){
            if(nums[start]==v[start]){
                start++;
            }
            else{
                break;
            }
        }
        
        while(start<end){
            if(nums[end]==v[end]){
                end--;
            }
            else{
                break;
            }
        }
        
        if(start>=end){
            return 0;
        }
        return end-start+1;
    }
};