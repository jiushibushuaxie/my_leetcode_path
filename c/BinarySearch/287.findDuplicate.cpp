/*
    287. 寻找重复数
    难度:中等
    给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。
    假设只有一个重复的整数，找出这个重复的数。

示例 1:
    输入: [1,3,4,2,2]
    输出: 2

示例 2:
    输入: [3,1,3,4,2]
    输出: 3

说明：
    不能更改原数组（假设数组是只读的）。
    只能使用额外的 O(1) 的空间。    不能用哈希表
    时间复杂度小于 O(n^2) 。
    数组中只有一个重复的数字，但它可能不止重复出现一次。
*/

/*
    抽屉原理：桌上有十个苹果，要把这十个苹果放到九个抽屉里，无论怎样放，我们会发现至少会有一个抽屉里面放不少于两个苹果。
    解法：二分。首先中间数是 (n+1)/2
        统计原始数组中小于等于这个中间数的元素的个数 cnt，如果 cnt 严格大于 mid，
        根据抽屉原理，重复元素就在区间 [left, mid] 里；
        （注意我加了着重号的部分「小于等于」、「严格大于」）。
        arr = [1,3,4,2,2] 此时数字在 1 — 5 之间

        mid = (1 + 5) / 2 = 3 arr小于等于的3有4个(1,2,2,3)，1到3中肯定有重复的值
        mid = (1 + 3) / 2 = 2 arr小于等于的2有3个(1,2,2)，1到2中肯定有重复的值
        mid = (1 + 2) / 2 = 1 arr小于等于的1有1个(1)，2到2中肯定有重复的值
        所以重复的数是 2 
*/

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

//方法一、抽屉原理
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1;
        int right = nums.size();
       
        while(left<right){
            int count = 0;
            int mid = left + (right-left)/2;
            for(int num : nums){
                if(num<=mid){
                    ++count;
                }
            }
            if(count<=mid){
                left = mid+1;
            }
            else{
                right = mid;
            }
        }
        return right;
    }
};

//参考链表找环入口的快慢指针
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0, slow = 0;
        while(true){
            fast = nums[nums[fast]];    //等于走了两步 里面一步，外面一步
            slow = nums[slow];
            if(slow == fast) {
                fast = 0;
                while(nums[slow] != nums[fast]) {
                    fast = nums[fast];
                    slow = nums[slow];
                }
                return nums[slow];
            }
        }
    }
};