//问题描述
/*
    122. 买卖股票的最佳时机 II
    给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
    设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
    注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1:

    输入: [7,1,5,3,6,4]
    输出: 7
    解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
        随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。


示例 2:

    输入: [1,2,3,4,5]
    输出: 4
    解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
        注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。
        因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。

示例 3:

    输入: [7,6,4,3,1]
    输出: 0
    解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。

提示：
    1 <= prices.length <= 3 * 10 ^ 4
    0 <= prices[i] <= 10 ^ 4
*/

//解法
/*
    贪心算法，只要第二天的价格大于第一天就计算利润，否则不计算
    “贪心算法” 在每一步总是做出在当前看来最好的选择。
    这道题 “贪心” 的地方在于，对于 “今天的股价 - 昨天的股价”，得到的结果有 3 种可能：正数  0  负数。
    贪心算法的决策是：只加正数。
    贪心算法和动态规划相比，它既不看前面（也就是说它不需要从前面的状态转移过来），
    也不看后面（无后效性，后面的选择不会对前面的选择有影响），因此贪心算法时间复杂度一般是线性的，空间复杂度是常数级别的。
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

//贪心算法
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i=0;i<prices.size()-1;i++){
            if(prices[i]<prices[i+1]) profit += prices[i+1] - prices[i];
            else continue;
        }
        return profit;
    }
};

/*动态规划
    https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/solution/tan-xin-suan-fa-by-liweiwei1419-2/
    可以用贪心算法解决的问题，一般情况下都可以用动态规划。
    因此，不妨从 “状态”、“状态转移方程” 的角度考虑一下，使用动态规划的思路解决这道问题。
    第 1 步：定义状态
    状态 dp[i][j] 定义如下
    第一维 i 表示索引为 i 的那一天（具有前缀性质，即考虑了之前天数的收益）能获得的最大利润；
    第二维 j 表示索引为 i 的那一天是持有股票，还是持有现金。这里 0 表示持有现金（cash），1 表示持有股票（stock）。

    第 2 步：思考状态转移方程
    第 3 步：确定起始
    第 4 步：确定终止   
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0 ) return 0;
        int len = prices.size();
        vector<vector<int>> DP(len,vector<int>(2,0));   //二维数组初始化；

        // 0：持有现金
        // 1：持有股票
        // 状态转移：0 → 1 → 0 → 1 → 0 → 1 → 0
        DP[0][0] = 0;
        DP[0][1] = -prices[0];    //第一天入手股票，收益率为-prices[0]，因为还没换成现金
        for(int i=1; i<prices.size();++i){
            DP[i][0] = max(DP[i-1][0],DP[i - 1][1] + prices[i]);
            DP[i][1] = max(DP[i-1][1],DP[i - 1][0] - prices[i]);
        }
        return DP[prices.size()-1][0];
    }
};