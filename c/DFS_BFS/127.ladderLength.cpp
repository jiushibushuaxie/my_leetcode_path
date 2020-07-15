/*
    127. 单词接龙
    难度：中等
    给定两个单词（beginWord 和 endWord）和一个字典，
    找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：
        1、每次转换只能改变一个字母。
        2、转换过程中的中间单词必须是字典中的单词。
说明:
    如果不存在这样的转换序列，返回 0。
    所有单词具有相同的长度。
    所有单词只由小写字母组成。
    字典中不存在重复的单词。
    你可以假设 beginWord 和 endWord 是非空的，且二者不相同。

示例 1:
输入:
    beginWord = "hit",
    endWord = "cog",
    wordList = ["hot","dot","dog","lot","log","cog"]
输出: 5
解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
     返回它的长度 5。

示例 2:
输入:
    beginWord = "hit"
    endWord = "cog"
    wordList = ["hot","dot","dog","lot","log"]
输出: 0
解释: endWord "cog" 不在字典中，所以无法进行转换。

*/

//解法
/*
    理解为一张无向图，顶点为单词，求最短路径
    BFS
    利用map表示图这个逻辑概念
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int> > Q;   //存储顶点 以及 步数  很关键，队列Q应该存储什么
        set<string> visit;          //已经访问的word顶点
        int ans = 0;

        map<string,vector<string>> graph;
        construct_graph(beginWord,wordList,graph);

        Q.push(make_pair(beginWord,1));
        visit.insert(beginWord);
        while(!Q.empty()){
            string node = Q.front().first;
            int step = Q.front().second;
            Q.pop();
            if(node == endWord){
                ans = step;
            }
            vector<string> neighbors = graph[node];
            for(int i=0;i<neighbors.size();++i){        //什么时候push进队列
                if(visit.find(neighbors[i]) == visit.end()){        
                    Q.push(make_pair(neighbors[i],step+1));
                    visit.insert(neighbors[i]);
                }
            }
        }
        return ans;
    }

    //connect用于表示两个word是否只有一个字母的不同
    bool connect(const string& word1,const string& word2){ 
        int cnt = 0;
        for(int i=0;i<word1.size();++i){
            if(word1[i]!=word2[i]){
                ++cnt;
            }
        }
        return cnt==1;
    }

    //图的构造函数
    void construct_graph(string& beginWord,vector<string>& wordList,   
                        map<string,vector<string>>& graph){
        wordList.push_back(beginWord);              //把beginWord push进wordList
        for(int i=0;i<wordList.size();++i){
            graph[wordList[i]] = vector<string>();
        }
        for(int i=0;i<wordList.size();++i){
            for(int j=i+1;j<wordList.size();++j){
                if(connect(wordList[i],wordList[j])){
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }
    }      
};