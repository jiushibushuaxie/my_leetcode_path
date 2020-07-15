/*
    739. 每日温度
    难度:中等
    根据每日 气温 列表，请重新生成一个列表，对应位置的输出是需要再等待多久温度才会升高超过该日的天数。
    如果之后都不会升高，请在该位置用 0 来代替。

    例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，
    你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。

    提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。
*/

//解法
/*
    单调栈，暴力方法就不说了
    栈里只有递减元素。
    该方法只需要对数组进行一次遍历，每个元素最多被压入和弹出堆栈一次，算法复杂度是 时间O(n) 空间O(n)。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> S;           //注意，栈里面存的是数组下标
        vector<int> ans(T.size(), 0);       //ans数组要初始化为0
        for(int i=0;i<T.size();++i){
            while(!S.empty()&&T[i]>T[S.top()]){              //什么时候出栈
                int preIndex = S.top();
                ans[preIndex] = i-preIndex;
                S.pop();
            }
            S.push(i);
        }
        return ans;
    }
};