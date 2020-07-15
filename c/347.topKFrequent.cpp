/*
    347. 前 K 个高频元素
    难度：中等
    给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

示例1:
    输入: nums = [1,1,1,2,2,3], k = 2
    输出: [1,2]

    输入: nums = [1], k = 1
    输出: [1]
*/

//解法
/*
    求前 k 大，用小顶堆，求前 k 小，用大顶堆。
    用小根堆，维护堆大小不超过 k 即可。每次压入堆前和堆顶元素比较，如果比堆顶元素还小，直接扔掉，否则压入堆。
    检查堆大小是否超过 k，如果超过，弹出堆顶。复杂度是 nlogk

    若用大顶堆，得把所有元素压入堆，复杂度是 nlogn（相当于堆排序），不便于海量数据处理
    priority_queue默认是最大堆

    最小堆定义方法
    priority_queue<pair<int,int>, vector< pair<int,int>>, greater<pair<int,int>>>
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <unordered_map>
#include <priority_queue>

using namespace std;   

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> record;  //(元素，频率)
        //遍历数组，录入频率
        for(int i = 0; i < nums.size(); i++){
            record[nums[i]]++;
        }
        int n = record.size();

        //优先队列中，按频率排序，所以数据对是(频率，元素)形式
        //最小堆定义方法, priority_queue默认是最大堆
        priority_queue< pair<int,int> , vector< pair<int,int> >, greater< pair<int,int> > > pq;
        for(auto it: record){
            if(k == pq.size()){ //队列已满
                if(it.second > pq.top().first){ ////堆排
                    pq.pop();
                    pq.push(make_pair(it.second,it.first));
                }
            }
            else{
                pq.push(make_pair(it.second,it.first));
            }
        }

        vector<int> result;
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }

        //翻转一下
        reverse(result.begin(), result.end());
        return result;
    }
};