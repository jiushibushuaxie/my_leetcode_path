/*
    647. 回文子串
    难度：中等
    给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
    具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被计为是不同的子串。

示例:
    输入: "abc"
    输出: 3
    解释: 三个回文子串: "a", "b", "c".

    输入: "aaa"
    输出: 6
    说明: 6个回文子串: "a", "a", "a", "aa", "aa", "aaa".

*/

//解法
/*
    同第5题类似
    1、回文串，中心扩展法
    2、动态规划
        1、子问题 左i右j 字符串的回文子串数dp[i][j]
        2、边界条件  dp[i][i] = 1
        3、状态转移方程 dp[i][j] = if(s[i]==s[j]) dp[i][j] = dp[i+1][j-1] + 1
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

//中心扩展法
class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        for(int i=0;i<s.size()-1;++i){
            ans += count_center(s,i,i+1) + count_center(s,i,i);
        }
        ans += count_center(s,s.size()-1,s.size()-1);
        return ans;
    }

    int count_center(string& s,int left,int right){
        int ans = 0;
        while(left>=0&&right<s.size()){
            if(s[left]==s[right]){
                ++ans;
                --left;
                ++right;            //注意，--left,++right写在if语句里面~~~！！！
            }
            else{
                break;
            }           
        }
        return ans;
    }
};

//动态规划
class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
        //初始化
        for(int i =0; i<s.size();++i){
            dp[i][i] = true;
        }

        //总是先得到小子串的回文数量，然后大子串才能参考小子串的结果
        for(int j=1;j<s.size();++j){        //右边界先固定
            for(int i=0;i<j;++i){
                if(s[i]==s[j]){                         //1、s[i]==s[j]
                    if(j-i<=2||dp[i+1][j-1]){           //2、且dp[i-1][j+1]也为回文子串（true）
                        dp[i][j] = true;        
                        ans++;
                    }
                }
                else {
                    dp[i][j] = false;
                }
            }
        }
        return ans+s.size();        //注意这里要加上s.size()
    }
};


int main(){
    string s = "abc";
    Solution solver;
    int ans = solver.countSubstrings(s);
    cout<<ans<<endl;
    return 0;
}
