//问题描述
/*
    求两个字符串的最大公共子串

    公共子序列和公共子串的区别在于，序列不要求连续，子串要求是其在原串中是连续的。

//解法
    LCS算法
    LCS (Longest Common Subsequence) 算法用于找出两个字符串最长公共子串。
    (1) 将两个字符串分别以行和列组成矩阵。
    (2) 计算每个节点行列字符是否相同，如相同则为 1。
    (3) 通过找出值为 1 的最长对角线即可得到最长公共子串。
    为进一步提升该算法，我们可以将字符相同节点(1)的值加上左上角(d[i-1, j-1])的值，
    这样即可获得最大公用子串的长度。如此一来只需以行号和最大值为条件即可截取最大子串。
*/
#include<iostream>
#include<vector>
using namespace std;

string LCS(const string &str1, const string &str2){
    if(str1.empty() || str2.empty()){
        return "";
    }
    int iMax=0;     //用于标记最长子串的长度
    int iIndex=-1;  //用于标记最长子串在str1的结束位置
    vector<vector<int> > vec(str1.size(), vector<int>(str2.size(),0));  //矩阵全部初始化为0

    for(int i=0;i!=str1.size();++i){
        for(int j=0;j!=str2.size();++j){
            if(str1[i] == str2[j]){
                int n;
                if(i>0&&j>0) {  //因为i-1要大于等于0
                    n = 1+vec[i-1][j-1];  //重要的一行代码 DP思想
                }
                else n=1;
                vec[i][j] = n;
                if(iMax<n){
                    iMax = n;
                    iIndex = i;
                }
            }
        }
    }
    if(iIndex == -1)
        return "";
    return str1.substr(iIndex-iMax+1,iMax);  //substr(pos, n) 两个参数，起始位置，长度
}

int main()
{
    string a = "aabcefde";
    string b = "abcd"; 
    cout <<  LCS(a,b) << endl; 
    system("pause");
    return 0;
}