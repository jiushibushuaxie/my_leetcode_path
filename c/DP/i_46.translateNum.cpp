/*
    面试题46. 把数字翻译成字符串
    难度：中等
    给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” 
    ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。
    一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

示例 1:
    输入: 12258
    输出: 5
    解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
*/

//解法
/*
    dp
    1、子问题：求以第i个数字为结尾的翻译方法数量
    2、dp[i] = dp[i-1]+ dp[i-2]  需要num[i-1]以及num[i]在0-25范围内。
    3、边界条件dp[0] = 1;dp[1] =1;
    4、状态转移方程 dp[i] = dp[i-1]+ dp[i-2]或dp[i] = dp[i-1]; 做判断。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int translateNum(int num) {
        if(num<=9){
            return 1;
        }
        vector<int> nums;
        while(num){
            nums.push_back(num%10);
            num = num/10;
        }
        reverse(nums.begin(),nums.end());
        
        vector<int> dp(nums.size(),0);
        dp[0] = 1;
        dp[1] = 1;
        if((nums[0]==1)||(nums[0]==2&&nums[1]<=5)){
            dp[1] = 2;
        }
        for(int i=2;i<nums.size();++i){
            if((nums[i-1]==1)||(nums[i-1]==2&&nums[i]<=5)){

                dp[i] = dp[i-1]+dp[i-2];
            }
            else{
                dp[i] = dp[i-1];
            }
        }
        return dp[nums.size()-1];
    }
};

int main(){
    int num = 25;
    Solution solver;
    int ans = solver.translateNum(num);
    cout<<ans<<endl;
    return 0;
}
