/*
    56. 合并区间
    难度：中等
    给出一个区间的集合，请合并所有重叠的区间。

示例 1:
    输入: [[1,3],[2,6],[8,10],[15,18]]
    输出: [[1,6],[8,10],[15,18]]
    解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].

示例 2:
    输入: [[1,4],[4,5]]
    输出: [[1,5]]
    解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。

*/

//解法
/*
    先排序，后合并
    并定义一个标记数组
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

bool cmp(vector<int>& a, vector<int>& b){
    return a[0]<b[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        vector<bool> flag(intervals.size(),true);
        vector<vector<int>> ans;
        int left = 0,right = 0;
        for(int i=0;i<intervals.size();++i){
            if(flag[i]){
                left = intervals[i][0];
                right = intervals[i][1];
                for(int j=i+1;j<intervals.size();++j){
                    if(right>=intervals[j][0]){
                        flag[j] = false;
                        right = max(right, intervals[j][1]);
                    }
                } 
                ans.push_back({left,right});
            }
        }
        return ans;
    }
};