/*
    560. 和为K的子数组
    难度：中等
    给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

示例:
    输入:nums = [1,1,1], k = 2
    输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
*/

//解法
/*
    注意需要考虑负数，且不能排序（排序会破坏顺序），滑动窗口考虑正负情况比较复杂（因为扩大窗口可能会使窗口和变小）

    1、前缀和思想：保存前i-1个元素和为pre[i]。结果超时

    2、哈希表
    扫描一遍数组, 使用map记录出现同样的和的次数, 对每个i计算累计和sum并判断map内是否有sum-k
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <map>

using namespace std;

//哈希表,有点难理解
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0;
        map<int,int> M;
        int sum=0;
        M[0] = 1;
        for(int i=0;i<nums.size();++i){
            sum += nums[i];
            if(M[sum-k]){
                ans += M[sum-k];
            }
            ++M[sum];
        }
        return ans;
    }
};

//前缀和超时
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> pre(nums.size(),0);
        int ans=0;
        for(int i=1;i<nums.size();++i){
            pre[i] = pre[i-1] + nums[i-1];
        }
        for(int i=0;i<nums.size();++i){
            for(int j=i;j<nums.size();++j){
                if(pre[j]-pre[i]+nums[j]==k){
                    ++ans;
                }
            }
        }
        return ans;
    }
};

