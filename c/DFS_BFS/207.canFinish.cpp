/*
    207. 课程表
    难度:中等
    你这个学期必须选修 numCourse 门课程，记为 0 到 numCourse-1 。
    在选修某些课程之前需要一些先修课程。
    例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们：[0,1]
    给定课程总量以及它们的先决条件，请你判断是否可能完成所有课程的学习？

示例 1:
    输入: 2, [[1,0]] 
    输出: true
    解释: 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的。

示例 2:
    输入: 2, [[1,0],[0,1]]
    输出: false
    解释: 总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0；
    并且学习课程 0 之前，你还应先完成课程 1。这是不可能的。
*/

/*
    解法：可以理解为有向图，判断图是否有环,有环则不能完成
    DFS
    BFS
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>

using namespace std;

//BFS，入度，有向图流入每个顶点的 边数
//若完成宽度优先搜索后，所有的入度都为0，则图无环，返回true
class Solution {
public:
   bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);   //保存每个顶点的入度
        vector<vector<int>> graph;//构建临接表（用vector储存临接点，方便访问）
        vector<int> v;      //只用于邻接表初始化
        for (int i = 0; i < numCourses; i++)    //顶点入度初始化，邻接表初始化
        {
            indegree[i] = 0;
            graph.push_back(v);
        }
        for (int i = 0; i < prerequisites.size(); i++)  //更新入度以及图邻接表
        {
            indegree[prerequisites[i][0]]++;
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);  //存的是出边
        }
        //将入度为0的顶点入队
        queue<int> myqueue;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
                myqueue.push(i);
        }
        int cnt = 0;    //已学习完的课程。
        while (!myqueue.empty())
        {
            int temp = myqueue.front();
            myqueue.pop();
            cnt++;
            //更新：
            for (int i = 0; i < graph[temp].size(); i++)
            {
                indegree[graph[temp][i]]--;
                if (indegree[graph[temp][i]] == 0)  //放在这里做！只判断邻接点。
                    myqueue.push(graph[temp][i]);
            }		
        }
        return cnt == numCourses;
    }
};
