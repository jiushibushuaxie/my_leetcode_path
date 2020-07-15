/*
    49. 字母异位词分组
    难度：中等
    给定一个字符串数组，将字母异位词组合在一起。
    字母异位词指字母相同，但排列不同的字符串。

示例:
    输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
    输出:
    [
        ["ate","eat","tea"],
        ["nat","tan"],
        ["bat"]
    ]
说明：
    所有输入均为小写字母。
    不考虑答案输出的顺序。

*/
/*
   哈希表
   怎样把字母异位词映射到同一个key上？将每个单词排序后作为key
*/
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string,vector<string>> map_str;
        string str = "";   
        for(int i=0; i<strs.size(); ++i){
            str = strs[i];
            sort(str.begin(),str.end());                //单词排序
            if(map_str.find(str)==map_str.end()){           //单词未在映射表里面
                map_str[str].push_back(strs[i]);                 //加入映射表
            }
            else{           //单词在映射表里面
                map_str[str].push_back(strs[i]);
            }
        }
        for(auto s:map_str){
            result.push_back(s.second);         //主要second不是函数，是成员数据
        }
        return result;
    }
};