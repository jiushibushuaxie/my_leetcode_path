//问题描述
/*
    406.根据身高重建队列
    难度：中等
    假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，
    其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。 
    编写一个算法来重建这个队列。

示例 1:
    输入:
    [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

    输出:
    [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/

/*
    解法：// 先排序
        // [7,0], [7,1], [6,1], [5,0], [5,2], [4,4]
        
        // 再一个一个插入。
        // [7,0]
        // [7,0], [7,1]
        // [7,0], [6,1], [7,1]
        // [5,0], [7,0], [6,1], [7,1]
        // [5,0], [7,0], [5,2], [6,1], [7,1]
        // [5,0], [7,0], [5,2], [6,1], [4,4], [7,1]
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

bool cmp(const vector<int>& a, const vector<int>& b){
    if (a[0] > b[0]) return true;
    if (a[0] == b[0] && a[1] < b[1]) return true;
    return false;
}
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(), cmp);
        vector<vector<int>> res;
        
        for(int i=0;i<people.size();++i){
            res.insert(res.begin() + people[i][1], people[i]);
        }
        return res;
    }
};

int main()
{
    Solution solver;
    vector<vector<int>> test_vec = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    vector<vector<int>> res = solver.reconstructQueue(test_vec);
    for(int i=0;i<res.size();++i){
        cout<<res[i][0]<<" "<<res[i][1]<<endl;
    }
    return 0;
}
