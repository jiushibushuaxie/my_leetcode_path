//问题描述
/*
    349.两个数组的交集 
    给定两个数组，编写一个函数来计算它们的交集。

示例 1:
    输入: nums1 = [1,2,2,1], nums2 = [2,2]
    输出: [2]

示例 2:
    输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
    输出: [9,4]

说明:
    输出结果中的每个元素一定是唯一的。
    我们可以不考虑输出结果的顺序。
*/

//解法
/*
    vector去重的两种方法
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.empty()||nums2.empty()) return {};
        vector<int> vec;
        for(auto i:nums1){
            for(auto j:nums2){
                if(i==j)
                    vec.push_back(i);
            }
        }
        
        //方法一 ：利用set的特性
        set<int> s(vec.begin(), vec.end());
        vec.assign(s.begin(), s.end());    //assign是赋值
        //完成去重
        

        // //方法二 ：vector去重，结合sort和unique以及erase;
        // sort(vec.begin(), vec.end());
        // vec.erase(unique(vec.begin(), vec.end()), vec.end());  //unique返回的是重复元素开始的地址
        return vec;
    }
};