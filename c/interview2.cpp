//给定一个升序数组，可能会有重复的数字，将数组里的数平方后，有多少不同的数。 
//例子，[-1，3，3]，返回结果 2.
//例子，[-1，-1，1，1]，返回结果 1.

/* 思路：使用双指针，对left和right的绝对值进行比较，
如果不相等，那么绝对值大的一边进行收缩，并且不相等的数加一，
但是要记录一下这个数的绝对值，这样碰到相同的可以越过去。
比如[-1，3，3]，一开始right绝对值为3，left绝对值为1，不相等，ans为1，记录pre为3，
右边向里面收缩一位，然后right绝对值还是3，left绝对值为1，
发现right和pre相等，越过，右边向里面收缩一位，
right绝对值为1，left绝对值为1，ans为2，循环结束。
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int howManyDiff(vector<int>& nums) {
    int left = 0;
    int right = nums.size()-1;
    int ans = 0;
    int pre = INT32_MAX;
    while(left <= right){
        if(abs(nums[left])<abs(nums[right])){
            if(abs(nums[right])!=pre){
                ++ans;
                pre = abs(nums[right]);
            }
            --right;
        }
        else{
            if(abs(nums[right])!=pre){
                ++ans;
                pre = abs(nums[left]);
            }
            ++left;
        }

    }
    return ans;
}

int main(){
    vector<int> nums = {-2,-1,-1,0,1,2};
    int ans = howManyDiff(nums);
    cout<<ans<<endl;
    return 0;
}
