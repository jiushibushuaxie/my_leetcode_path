/*
    290. 单词规律
    难度：简单
    给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。
    这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。

示例1:
    输入: pattern = "abba", str = "dog cat cat dog"
    输出: true
示例 2:
    输入:pattern = "abba", str = "dog cat cat fish"
    输出: false
示例 3:
    输入: pattern = "aaaa", str = "dog cat cat dog"
    输出: false
示例 4:
    输入: pattern = "abba", str = "dog dog dog dog"
    输出: false
*/
/*
   哈希表
   设置单词（字符串）到字符（字母）pattern的哈希映射
   同时需要一个字母数组，用于表示是否字母使用过
*/
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<string, char> word_map;       //单词到字母的映射表
        char used[128] = {0};           //已被映射的字母
        string word;                    //临时保存拆分出的单词
        int pos = 0;                //指向字母
        str.push_back(' ');     //便于最后一个单词的拆分
        for(int i=0; i<str.size();++i){
            if(str[i]== ' '){
                if(pos == pattern.size()){      //分割出单词，但是没有字母对应了
                    return false;
                }
                if(word_map.find(word) == word_map.end()){  //word未出现在映射表里
                    if(used[pattern[pos]]==1){
                        return false;               //但对应下标字母被用过，返回false
                    }
                    word_map[word] = pattern[pos];      //对应下标字母没有被用过，加入映射表中
                    used[pattern[pos]] = 1;             //标记被用过了
                }
                else if(word_map.find(word) != word_map.end()){  //word出现在映射表里
                    if(word_map[word] != pattern[pos]){          //但映射对应不一致，返回false
                        return false;
                    }
                }
                word = "";          //word清零
                pos++;
            }
            else{
                word += str[i];
            }
        }
        if(pos!=pattern.length()){          //当字母大于单词数量 return false;
            return false;
        }
        return true;
    }
};