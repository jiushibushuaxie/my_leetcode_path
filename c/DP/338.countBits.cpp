/*
    338. 比特位计数
    难度：中等
    给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，
    计算其二进制数中的 1 的数目并将它们作为数组返回。
示例:
    输入: 2
    输出: [0,1,1]

    输入: 5
    输出: [0,1,1,2,1,2]

*/

//解法
/*
    分奇偶数来考虑
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num+1);
        result[0] = 0;              //初始值
        for(int i = 1; i <= num; i++){
            if(i % 2 == 1){
                result[i] = result[i-1] + 1;     //关键，偶数二进制1的个数就等于result[i-1] + 1
            }
            else{
                result[i] = result[i/2];    //关键，偶数二进制1的个数就等于i/2的个数
            }
        }
        return result;
    }
};

