//问题描述
/*
    254. 因子的组合
    难度：中等
    整数可以被看作是其因子的乘积。
    例如：
    8 = 2 x 2 x 2;
      = 2 x 4.
    请实现一个函数，该函数接收一个整数 n 并返回该整数所有的因子组合。

示例 1:
    输入: 1
    输出: []
示例 2:
    输入: 37
    输出: []
示例 3:
    输入: 12
    输出:
    [
    [2, 6],
    [2, 2, 3],
    [3, 4]
    ]
示例 4:
    输入: 32
    输出:
    [
    [2, 16],
    [2, 2, 8],
    [2, 2, 2, 4],
    [2, 2, 2, 2, 2],
    [2, 4, 4],
    [4, 8]
    ]

    //解法：C++使用递归+dfs
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    // l 代表因子的起始数，保证因子的有序性可以做到天然的去重
    vector<vector<int> > dfs(int n, int l) {
        vector<vector<int> > res;
        for (int i = l; i * i <= n; ++i) {
            if (n % i == 0) {
                res.push_back({n / i, i});
                for (auto v : dfs(n / i, i)) {
                    v.push_back(i);
                    res.push_back(v);
                }
            }
        }
        return res;
    }
    vector<vector<int>> getFactors(int n) {
        return dfs(n, 2);
    }
};
