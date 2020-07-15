//问题描述
/*
    Cassidy和Eleanore是一对好朋友，她们经常会一起玩游戏。某一天她们玩了一个回文游戏。
    游戏规则是这样的：给出一个仅包含小写字母的字符串S，在每一个人的回合中，她们会进行两个操作：

    1. 尝试重新排列这个字符串，如果可以把这个字符串排列成回文字符串，则立即获胜。

    2. 否则，她们必须删掉字符串中的一个字符。

    已知，Cassidy先手，在两个人都采取最佳策略的情况下，谁可以获胜。

    输入：第一行仅包含一个正整数t，表示数据组数，(t<=10)。
    接下来有t行，每行有一个字符串S，表示一组测试数据。(|S|<=1000)

    对于每组数据输出一行，如果Cassidy获胜，则输出Cassidy，否则输出Eleanore
*/

//解法
/*
   

*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;
using std::string;
using std::vector;

bool IsHuiwen(string s){
    for(int i=0;i<s.size();i++){

    }
}

int main(int argc, char const *argv[])
{
    
    int t; //数据组数
    cin>>t;
    vector<string> ss(t);
    for(int i=0;i<t;i++){
        cin>>ss[i];
    }
    
    // for(int j=0;j<t;j++){
    //     cout<<ss[j]<<endl;
    // }
    vector<string> result{t};
    // 如果字符串不能重新排列成回文串，则奇数长Cassidy获胜，偶数长Eleanore获胜
    //怎么判断一个字符串能够排列成回文串呢?  【leetcode】266 回文排列（字符串）
    for(int j=0;j<t;j++){
        if(IsHuiwen(ss[j]))
        {
            cout<<"Cassidy"<<endl;
        }
        else if(ss[j].size()%2 == 1)
        {
            cout<<"Cassidy"<<endl;
        }
        else if(ss[j].size()%2 == 0) 
        {
            cout<<"Eleanore"<<endl;
        }
        
    }


    return 0;
}
