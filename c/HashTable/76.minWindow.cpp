/*
    76. 最小覆盖子串
    难度：困难
    给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字符的最小子串。

示例：
    输入: S = "ADOBECODEBANC", T = "ABC"
    输出: "BANC"

说明：
    如果 S 中不存这样的子串，则返回空字符串 ""。
    如果 S 中存在这样的子串，我们保证它是唯一的答案。
*/

//解法
/*
   哈希表，滑动窗口 与第三题类似
   为什么可以用滑动窗口，存在矛盾情况：包含T所有字符，但要求子串最小
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int map_w[128] = {0};
        int map_t[128] = {0};
        vector<int> vec_t;          //vec_t记录T中有哪些字符

        for(int i=0;i<t.size();++i){
            map_t[t[i]]++;          //字符串T哈希映射
        }
        for(int i=0;i<128;++i){
            if(map_t[i]>0){
                vec_t.push_back(i);         //i代表字符ascii码
            }
        }

        int start = 0;          //窗口起始点
        int end = 0;            //窗口终止点
        string result;
        
        while(end<s.size()){
            map_w[s[end]]++;      //窗口中字符哈希映射
            for(int i=start;i<end;i++){  
                char start_ch = s[i];
                if(map_t[start_ch]==0){     //如果start_ch字符没有出现在T中
                    start = i+1;            //向前移动
                }
                else if(map_w[start_ch]>map_t[start_ch]){       
                    //如果start_ch字符出现在T中,且map_w中start_ch字符数量大于map_t中start_ch字符数量
                    map_w[start_ch]--;  //map_w维持的是窗口中字符哈希映射
                    start = i+1;        //向前移动窗口
                }
                else{
                    //其他情况，不用再移动窗口头部，跳出循环，执行end++，移动窗口尾部
                    break;
                }
            }
            //判断一下当前窗口是否包含字符串t,同时根据子串长度来记录result
            if(is_window_ok(map_w,map_t,vec_t)){  //map_t,vec_t是不变的，代表字符串T，只有窗口map_w变化
                int length = end-start+1;
                if(result==""||result.size()>length){
                    result = s.substr(start,length);
                }
            }
            end++;
        }
        return result;
    }

    bool is_window_ok(int map_w[],int map_t[], vector<int> &vec_t){
        //判断map_t中的字符数量是否在map_w中都有  map_t是否位map_w子集
        for(int i=0;i<vec_t.size();++i){
            if(map_w[vec_t[i]]<map_t[vec_t[i]]){
                return false;
            }
        }
        return true;
    }
};