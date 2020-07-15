/*
    470. 用 Rand7() 实现 Rand10()
    难度：中等
    已有方法 rand7 可生成 1 到 7 范围内的均匀随机整数，试写一个方法 rand10 生成 1 到 10 范围内的均匀随机整数。
    不要使用系统的 Math.random() 方法。

    rand7 已定义。
    传入参数: n 表示 rand10 的调用次数。

*/

/*

*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

class Solution {
public:
    int rand10() {
        int temp;
        while(true){    
            temp = 7*(rand7() - 1) + rand7()-1;
            if(temp<40) {       //剔除大于40的值，1-40等概率出现。
                break;
            }
        }
        return temp%10 + 1;
    }
};