/*
    402. 移掉K位数字
    难度:中等
    给定一个以字符串表示的非负整数 num，移除这个数中的 k 位数字，使得剩下的数字最小。

注意:
    num 的长度小于 10002 且 ≥ k。
    num 不会包含任何前导零。


示例 1 :
    输入: num = "1432219", k = 3
    输出: "1219"
    解释: 移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219。

示例 2 :
    输入: num = "10200", k = 1
    输出: "200"
    解释: 移掉首位的 1 剩下的数字为 200. 注意输出不能有任何前导零。

示例 3 :
    输入: num = "10", k = 2
    输出: "0"
    解释: 从原数字移除所有的数字，剩余为空就是0。


*/

/*
    解法：贪心+栈（vector表示栈）
    用字符串表示整数，用于表示特别大的整数

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

/*
//自己写的。28/33 通过测试用例
class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        if(k==num.size()) return "0";
        
        for(int i=0;i<num.size()-1;++i){
            if(num[i]-num[i+1]>0){
                --k;
            }
            else{
                res += num[i];
            }
            if(k==0) {          //k减完了
                res += num.substr(i+1,num.size()-(i+1));
                break;
            }
        }
        if(k>0){                        //k没有减完，字符串中 没有k种前一字符大于后一字符的情况
            res = res.substr(0,res.size()-k+1);  //只能保证前面字符是从小到大的
            //不能保证最后一个字符大于前面字符
            char temp = res[res.size()-1];
            if(temp-num[num.size()-1]>0){
                res = res.substr(0,res.size()-1) + num[num.size()-1]; 
            }
        }

        //对前面的0进行处理
        int j=0;
        while(j<res.size()&&res[j]=='0') ++j;
        res = res.substr(j,res.size()-j);
        if(res=="") res = "0";

        return res;
    }
};
*/


//贪心+栈
class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<int> S;  //使用vector作为栈，栈只是操作重要，不一定要stack
        string result = "";
        for(int i=0;i<num.size();++i){
            int number = num[i]-'0';
            while(S.size() && number<S[S.size()-1] && k>0){
                S.pop_back();    //出栈,--k;
                --k;
            }
            if(S.size()!=0 || number!=0){   //什么时候入栈？number为0且栈不会空时，可入栈
                S.push_back(number);
            }
        }
        while(S.size() && k>0){         //循环一遍数组后，k仍然大于0
            S.pop_back();           //出栈，--k
            --k;
        }
        for(int i=0;i<S.size();++i){
            result += to_string(S[i]);
        }
        if(result == ""){
            result = "0";
        }
        return result;
    }
};


int main()
{
    Solution solver;
    string test = "1234567890";
    int k=9;
    string res = solver.removeKdigits(test,k);
    cout<<res<<endl;
    return 0;
}
