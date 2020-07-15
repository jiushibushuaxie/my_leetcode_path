//问题描述
/*
    136.只出现一次的数字 
    只出现一次的数字
    给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
    你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
例1
    输入: [2,2,1]
    输出: 1
例2
    输入: [4,1,2,1,2]
    输出: 4
*/

//解法
/*
    利用位运算进行求解   a⊕0 = a       a⊕a = 0
    XOR 运算满足交换律和结合律： a⊕b⊕a = (a⊕a)⊕b = 0⊕b = b
    异或符号 ^
    时间复杂度O(n),空间复杂度O(n)
*/

#include <iostream>
#include <vector>
using namespace std;
using std::vector;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int num:nums){
            ans ^=num;
        }
        return ans;

    }
};

//测试块
int main(int argc, const char** argv) {
    vector<int> test_array = {1,4,5,1,4,5,8};
    Solution solver;
    int ans= solver.singleNumber(test_array);
    cout<<ans<<endl;
    return 0;
}

