//问题描述
/*
   为了找到自己满意的工作，牛牛收集了每种工作的难度和报酬。
   牛牛选工作的标准是在难度不超过自身能力值的情况下，牛牛选择报酬最高的工作。
   在牛牛选定了自己的工作后，牛牛的小伙伴们来找牛牛帮忙选工作，牛牛依然使用自己的标准来帮助小伙伴们。
   牛牛的小伙伴太多了，于是他只好把这个任务交给了你。

输入：
    每个输入包含一个测试用例。
    每个测试用例的第一行包含两个正整数，分别表示工作的数量N(N<=100000)和小伙伴的数量M(M<=100000)。
    接下来的N行每行包含两个正整数，分别表示该项工作的难度Di(Di<=1000000000)和报酬Pi(Pi<=1000000000)。
    接下来的一行包含M个正整数，分别表示M个小伙伴的能力值Ai(Ai<=1000000000)。
    保证不存在两项工作的报酬相同。

输出描述:
    对于每个小伙伴，在单独的一行输出一个正整数表示他能得到的最高报酬。一个工作可以被多个人选择。

示例1
输入
    3 3 
    1 100 
    10 1000 
    1000000000 1001 
    9 10 1000000000

输出
    100 
    1000 
    1001
*/

//解法
/*
    用pair双排序，双指针
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;


int main() {
    int n;  //工作数量
    int m;  //小伙伴人数
    while(cin >> n >> m) {
        vector<pair<int, int> > job(n + 1); //pair将2个数据组合成一组数据, job里面包含<工作难度，工作报酬>
        vector<pair<int, int> > guy(m);  //两个值可以分别用pair的两个公有函数first和second访问。 guy包含<能力值，第i个人>
        vector<int> map(m);
        int mx = 0, index = 0, left = 0;
        job[0] = make_pair(0, 0);   // make_pair 创建一个pair对象
        for(int i = 1; i <= n; ++ i) {
            cin >> job[i].first >> job[i].second;
        }
        for(int i = 0; i < m; ++ i) {
            cin >> guy[i].first;
            guy[i].second = i;
        }
        sort(job.begin(), job.end(), [&](pair<int, int> a, pair<int, int> b){return a.first < b.first;});//按工作难度小到大排序
        sort(guy.begin(), guy.end(), [&](pair<int, int> a, pair<int, int> b){return a.first < b.first;});//按能力值从小到大排序
        for(int i = 0; i <= n; ++ i) {
            mx = max(mx, job[i].second);
            job[i].second = mx;    //重要：这样对每个工作难度，都有最大的报酬，而不是输入的对应的报酬
        }
        while(left < m && index < n + 1) {
            if(guy[left].first >= job[index].first)  ++index;  //当小伙伴的能力值大于工作难度，加大工作难度
            else {
                map[guy[left].second] = job[index - 1].second;  //得到小伙伴的最大报酬  map的下标表示第i个小伙伴，数据代表报酬
                ++ left;
            }
        }
        for(int i = left; i < m; ++ i) {  // 应该是此时index>=n+1，剩下的所有人的能力值都超过最大报酬对应的工作难度，所以剩下所有人都是最大报酬
            map[guy[i].second] = job[n].second;
        }
        for(int i = 0; i < m; ++ i) {
            cout << map[i] << endl;
        }
    }
}