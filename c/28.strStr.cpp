/*
    28.实现 strStr()  
    给定一个 haystack 字符串和一个 needle 字符串，
    在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。
    如果不存在，则返回  -1。
    
示例 1:
    输入: haystack = "hello", needle = "ll"
    输出: 2


示例 2:
    输入: haystack = "aaaaa", needle = "bba"
    输出: -1

*/

//解法
/*
    (模式串匹配问题)  kmp算法时间复杂度 o(m+n) 
    https://leetcode-cn.com/problems/implement-strstr/solution/kmp-suan-fa-xiang-jie-by-labuladong/
    此处用的是双指针
    注意：strStr函数返回值是int型，所以一定要有返回值；
    如果所有的返回函数return均存在条件判断下，会报错，如if(count==n){return i;}，
    所以一定要有一个return函数是不属于条件判断下的。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int h=haystack.size(),n=needle.size(),j,count;
        if(n>h)
            return -1;
        for(int i=0;i<h-n+1;i++){
            j=0;
            count=0;
            while(haystack[i+j]==needle[j]&&needle[j]!='\0'){
                j++;
                count++;
            }
            if(count==n)
                return i;
        }
        return -1;
    }
};