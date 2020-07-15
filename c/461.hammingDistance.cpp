/*
    461. 汉明距离
    难度:简单
    两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。
    给出两个整数 x 和 y，计算它们之间的汉明距离。

示例
    输入: x = 1, y = 4

    输出: 2

    解释:
    1   (0 0 0 1)
    4   (0 1 0 0)
           ↑   ↑
*/

/*
    位运算
    左移与右移的区别
    对于有符号数
        左移：  右边空出的低位用0填补，舍弃左边高位
        右移（非负）：  左边空出的高位用0填补，舍弃右边低位
        右移（负数）：  左边空出的高位用1填补，舍弃右边低位
    对于无符号数
        左移：  右边空出的低位用0填补，舍弃左边高位
        右移：  左边空出的高位用0填补，舍弃右边低位
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

class Solution {
public:
    int hammingDistance(int x, int y) {
        int distance = 0;
        for(int i=0;i<32;++i){
            if((x&1) != (y&1)){
                ++distance;
            }
            x = x>>1;       //注意是右移，不能左移
            y = y>>1;
        }
        return distance;
    }
};