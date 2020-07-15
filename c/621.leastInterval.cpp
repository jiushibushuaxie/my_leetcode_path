/*
    621. 任务调度器
    难度：中等
    给定一个用字符数组表示的 CPU 需要执行的任务列表。其中包含使用大写的 A - Z 字母表示的26 种不同种类的任务。
    任务可以以任意顺序执行，并且每个任务都可以在 1 个单位时间内执行完。
    CPU 在任何一个单位时间内都可以执行一个任务，或者在待命状态。

    然而，两个相同种类的任务之间必须有长度为 n 的冷却时间，
    因此至少有连续 n 个单位时间内 CPU 在执行不同的任务，或者在待命状态。

    你需要计算完成所有任务所需要的最短时间。

示例:
    输入：tasks = ["A","A","A","B","B","B"], n = 2
    输出：8
解释：A -> B -> (待命) -> A -> B -> (待命) -> A -> B.
     在本示例中，两个相同类型任务之间必须间隔长度为 n = 2 的冷却时间，而执行一个任务只需要一个单位时间，所以中间出现了（待命）状态。 
*/

//解法
/*
    应当尽早安排出现次数较多的任务
    假设 A 为出现次数最多的任务，假设其出现了 p 次，
    考虑到冷却时间，那么执行完所有任务的时间至少为 (p - 1) * (n + 1) + 1。
    可以发现，CPU 产生了 (p - 1) * n 个空闲时间，只有 p 个时间是在工作的。
    考虑把剩余的任务安排到这些空闲时间里~
    可能会出现多个频率最高的任务,因此最后要加上频率最高的不同任务的个数 maxCount
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ans = 0;
        vector<int> count(26,0);;
        for(int i=0;i<tasks.size();++i){
            ++count[tasks[i]-'A'];
        }
        sort(count.begin(),count.end()); //排序
        //统计有多少个频率最高的字母
        int maxCount = 0;
        for (int i = 25; i >= 0; i--) {
            if(count[i] != count[25]){
                break;
            }
            maxCount++;
        }
       
        //公式算出的值可能会比数组的长度小，如["A","A","B","B"]，n = 0，此时要取数组的长度
        if((count[25] - 1) * (n + 1) + maxCount > tasks.size()){
            ans = (count[25] - 1) * (n + 1) + maxCount;
        }
        else{
            ans = tasks.size();
        }
        // ans = max((count[25]-1)* (n + 1) + maxCount,(int)tasks.size());
        return ans;
    }
};