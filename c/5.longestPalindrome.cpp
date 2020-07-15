//问题描述
/*
    5. 最长回文子串
    难度：中等
    给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

    输入: "babad"
    输出: "bab"
    注意: "aba" 也是一个有效答案。

示例 2：

    输入: "cbbd"
    输出: "bb"

*/

//解法
/*
   中心扩展法最好  马拉车算法太难了，需要补#
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

//暴力法，超时
class Solution {
public:
    string reverse_string(string str){
        string result = str;
        int i =0;
        while(i<str.size()/2){
            swap(result[i],result[result.size()-1-i]);
            i++;
        }
        return result;
    }
    //substr i为起始位置，j为长度
    string longestPalindrome(string s) {
        int i=0;
        int j=0;
        int count =0;
        int start = 0;
        if(s.size()<2) return s;
        for(i=0;i<s.size();++i){
            for(j=1;j<s.size()-i+1;j++){
                if(s.substr(i,j)==reverse_string(s.substr(i,j))) {
                    if(count<j){
                        start = i;
                        count = j;
                    }
                }
            }
        }
        return s.substr(start,count);
    }
};

//DP动态规划j
// DP[i][j] 第一位i表示str的第i个字符（左边）， j为第j个字符(右边)
class Solution {
public:
    string longestPalindrome(string str){
        int len = str.size();
        int start = 0;
        int end = 0;
        vector<vector<int>> DP(len, vector<int>(len,0) );

        //先初始化二维数组（对角线）
        for(int i=0;i<len;i++){
                DP[i][i]=1;
        }

        //总是先得到小子串的回文判定，然后大子串才能参考小子串的判断结果。
        //所有右边界从小到大
        for(int j=1;j<len;++j){
            for(int i=0;i<j;++i){
                if(str[i]==str[j])  {
                    if(j-i<=2||DP[i+1][j-1]) {         //j-1<i+1
                        DP[i][j] = 1;
                    }
                }
                else {
                    DP[i][j] = 0; 
                }

                if(DP[i][j]) { 
                    if(end - start<j-i){
                        start = i;
                        end =j;
                    }
                }
            }
        }
        return str.substr(start,end-start+1);
    }
};

//中心扩展法
class Solution {
public:
    string longestPalindrome(string str){
        int len = str.size();
        int begin_index = 0;
        int max_len = 0;
        for(int i=0;i<len;++i){
            int len1 = CenterExpender(str,i,i);
            int len2 = CenterExpender(str,i,i+1);
            int temp =  max(len1,len2);
            if(temp>max_len)  {
                max_len = temp;
                begin_index = i- (max_len-1)/2;
            }
        }
        return str.substr(begin_index ,max_len);
    }

    int CenterExpender(string str,int L, int R){
        while(L>=0&&R<str.size()){
            if(str[L]==str[R]) {
                --L;
                ++R;
            }
            else break;
        }
        return R-L-1;
    }
};