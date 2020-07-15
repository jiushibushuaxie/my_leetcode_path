//问题描述
/*
    121. 买卖股票的最佳时机
    给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
    如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。
    注意：你不能在买入股票前卖出股票。


示例 1:

    输入: [7,1,5,3,6,4]
    输出: 5
    解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
        注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。


示例 2:

    输入: [7,6,4,3,1]
    输出: 0
    解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。


提示：
    1 <= prices.length <= 3 * 10 ^ 4
    0 <= prices[i] <= 10 ^ 4
*/

//解法
/*
    DP动态规划
    第i天的最大收益 = max{第i-1天最大收益， 第i天价格-之前最小价格 }
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = 0x3f3f3f3f;
        int i_get = 0;
        int i_1_get = 0;
        for(int i=0;i<prices.size();++i){
            if(min_price>prices[i]) min_price=prices[i];
            i_get = max(i_1_get, prices[i]-min_price);
            i_1_get = i_get;
        }
        return i_get;
    }
};