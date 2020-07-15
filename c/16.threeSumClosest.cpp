/*
    16. 最接近的三数之和
    难度:中等
    给定一个包括 n 个整数的数组 nums 和 一个目标值 target。
    找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

示例:
    输入：nums = [-1,2,1,-4], target = 1
    输出：2
    解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。

*/

/*
    解法：排序+双指针
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int N = nums.size();
        int min_diff = INT_MAX;
        int ans = 0;
        for(int i=0;i<N-2;++i){         //第一个数做for循环，其余两个数分别为left right;
            int left = i+1;
            int right = N-1;
            while(left<right){
                int diff = target - nums[left] - nums[i] - nums[right];
                if(diff==0){
                    return target;
                }
                else if(diff>0){
                    if(min_diff > diff){
                        min_diff = diff;
                        ans =  target - min_diff;
                    }
                    ++left;
                }
                else if(diff<0){                
                    if(min_diff > -diff){
                        min_diff = -diff;
                        ans = target + min_diff;
                    }
                    --right;
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {-1,2,1,-4};
    int target = 1;
    Solution solver;
    int ans = solver.threeSumClosest(nums,target);
    cout<<ans<<endl;
    return 0;
}
