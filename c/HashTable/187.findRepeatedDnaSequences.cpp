/*
    187. 重复的DNA序列
    难度：中等
    所有 DNA 都由一系列缩写为 A，C，G 和 T 的核苷酸组成，例如：“ACGAATTCCG”。
    在研究 DNA 时，识别 DNA 中的重复序列有时会对研究非常有帮助。

    编写一个函数来查找目标子串，目标子串的长度为 10，且在 DNA 字符串 s 中出现次数超过一次。

示例：
    输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
    输出：["AAAAACCCCC", "CCCCCAAAAA"]  
    解释："AAAAACCCCC"出现两次，"CCCCCAAAAA"出现两次
*/

//解法
/*
   哈希表
   简单的哈希表，因为长度固定为10
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    std::vector<std::string> findRepeatedDnaSequences(std::string s) {
    	std::map<std::string, int> word_map;
    	std::vector<std::string> result;
    	for (int i = 0; i < s.length(); i++){
    		std::string word = s.substr(i, 10);
	    	if (word_map.find(word) != word_map.end()){
	    		word_map[word] += 1;
	    	}
	    	else{
	    		word_map[word] = 1;
	    	}
	    }
	    std::map<std::string, int> ::iterator it;
	    for (it = word_map.begin(); it != word_map.end(); it++){
    		if (it->second > 1){
		    	result.push_back(it->first);
		    }
    	}
    	return result;
    }
};