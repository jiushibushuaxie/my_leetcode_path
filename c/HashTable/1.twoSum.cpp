//问题描述
/*
    1.两数之和
    给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
    你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
例1
    给定 nums = [2, 7, 11, 15], target = 9

    因为 nums[0] + nums[1] = 2 + 7 = 9
    所以返回 [0, 1]
*/

//解法
/*
    暴力解法,两层循环
    哈希表
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

//暴力
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j;
        for(i = 0; i< nums.size() -1; i++){
            for(j = i+1; j< nums.size(); j++){
                if( nums[i]+nums[j] == target)
                {
                    return {i,j};
                }
            }
        }
    return {};
    }
};

//两遍哈希表
// 该方法用map实现，map是STL的一个关联容器，它提供一对一的数据处理能力
//（其中第一个可以称为关键字，每个关键字只能在map中出现一次，第二个可能称为该关键字的值）

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> a;     //建立hash表存放数组元素
        vector<int> b(2,-1);//存放结果
        for(int i=0;i<nums.size();i++)
            a.insert(map<int,int>::value_type(nums[i],i));
        for(int i=0;i<nums.size();i++)
        {   // 使用count，返回的是被查找元素的个数。如果有，返回1；否则，返回0。   注意：查找的都是key值而不是value值
            // 注意，map中不存在相同元素，所以返回值只能是1或0。
            if(a.count(target-nums[i])>0&&(a[target-nums[i]]!=i))
            //判断是否找到目标元素 且 目标元素不能是本身
            {
                b[0]=i;
                b[1]=a[target-nums[i]];
                break; //只需找到第一个
            }
        }
        return b;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> hash_map; //哈希表  
        for(auto i=0;i!=nums.size();i++){
            hash_map[nums[i]] = i;   //初始化哈希表  即数据与下标对换
        }
        for(auto i=0;i!=nums.size();i++){
            // 使用find，返回的是被查找元素的位置，没有则返回map.end()。注意：查找的都是key值而不是value值
            //如果存在对应的key值，且对应的key值中的value不等于i(即本身)
            if(hash_map.find(target-nums[i])!=hash_map.end()&& hash_map[target-nums[i]]!=i ){
                return {i,hash_map[target-nums[i]]};
            }
        }
        return {};
    }
};



//一遍哈希表
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(m.find(target-nums[i]) != m.end()){       //m中存在对应的键值
                return {m[target-nums[i]] , i};         //因为i为较大的元素，此时添加进去的键值都还小于i，所以i在后面
            }
            m[nums[i]]=i;       //向map中添加元素  记录好下标
        }
        return {};
    }
};


int main(int argc, const char** argv) {
    vector<int> test_array = {1,4,5,1,4,5,8};
    int target = 9;
    Solution solver;
    vector<int> ans= solver.twoSum(test_array, target);
    for(int i = 0; i< ans.size(); i++){
        cout<<ans[i]<<"\t";
    }
    
    return 0;
}