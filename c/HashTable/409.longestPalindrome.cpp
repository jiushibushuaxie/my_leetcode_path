/*
    409. 最长回文串
    难度：简单
    给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
    在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。
示例 1:
    输入:
    "abccccdd"
    输出:
    7
    解释:
    我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。

*/
/*
   哈希表
*/

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> hash_table;
        int ans = 0;
        for(auto c:s){
            hash_table[c]++;
        }
        for (auto p : hash_table) {
            int v = p.second;
            if (v % 2 == 1 && ans % 2 == 0)   //选取一个单字符作为中心。
                ++ans;
            ans += v / 2 * 2;       //偶数次出现的字符一定可以组成回文串 。 大于2的出现次数，取2的倍数次
        }
        return ans;
    }
};

//视频解法
class Solution {
public:
    int longestPalindrome(string s) {
        int char_map[128] = {0};
        int max_length = 0;
        int flag =0;
        for(int i=0;i<s.size();++i){
            char_map[s[i]]++;
        }
        for(int i=0;i<128;++i){
            if(char_map[i]%2==0){
                max_length += char_map[i];
            }
            else{
                max_length += char_map[i]-1;
                flag = 1;
            }
        }
        return max_length +flag;
    }
};