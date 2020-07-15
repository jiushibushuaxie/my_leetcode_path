/*
    554. 砖墙
    难度:中等
    你的面前有一堵方形的、由多行砖块组成的砖墙。 这些砖块高度相同但是宽度不同。你现在要画一条自顶向下的、穿过最少砖块的垂线。
    砖墙由行的列表表示。 每一行都是一个代表从左至右每块砖的宽度的整数列表。

    如果你画的线只是从砖块的边缘经过，就不算穿过这块砖。
    你需要找出怎样画才能使这条线穿过的砖块数量最少，并且返回穿过的砖块数量。

示例:
    输入[[1,2,2,1],
        [3,1,2],
        [1,3,2],
        [2,4],
        [3,1,2],
        [1,3,1,1]]

输出: 2

*/

/*
    解法：哈希表
    统计前缀和
    注意不要将最后一列算上！
    return row(行数) - 前缀和一样的 最大数目
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <map>

using namespace std;

//暴力 超时
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int row = wall.size();
        if(row==0) return 0;
        int column = 0;
        for(int i=0;i<wall[0].size();++i){
            column +=wall[0][i];
        }
        if(column<2) return row;
        int min_count = INT_MAX;
        for(int i=1;i<column;++i){
            int count = 0;
            for(int j=0;j<row;++j){
                int temp = 0;
                for(int k=0;k<wall[j].size();++k){
                    temp += wall[j][k];
                    if(temp==i) break;  
                    if(temp>i) {
                        ++count; 
                        break;
                    }
                }
            }
            min_count = min(min_count,count);
        }
    return min_count;
    }
};

//哈希表
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int row = wall.size();
        if(row==0) return 0;
        int column = 0;
        for(int i=0;i<wall[0].size();++i){
            column +=wall[0][i];
        }
        if(column<2) return row;
        
        map<int,int> mp;
        for(int i=0;i<row;++i){
            int temp = 0;
            for(int j=0;j<wall[i].size()-1;++j){
                temp +=wall[i][j];
                if(mp[temp])
                    mp[temp]++;
                else mp[temp] = 1;
            }
        }
        //map的遍历用迭代器，或范围for循环， 且调用first ,second 成员函数
        int res = 0;
        for(auto data: mp){
            res = max(res,data.second);
        }
        return row-res;
    }
};


int main()
{
    vector<vector<int>> wall = {{1,1},{2},{1,1}};
    Solution solver;
    int ans = solver.leastBricks(wall);
    cout<<ans<<endl;
    return 0;
}
