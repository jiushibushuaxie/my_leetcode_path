//问题描述
/*
    有n位小朋友去小明家里拜年，小明准备了m份礼物。小明想把所有礼物平均分给每个小朋友，每个小朋友得到相同个数的礼物。但是m未必能被n整除，
    小明可以使用以下两种操作任意多次（两种操作可以同时使用）。

    1、 给其中一个小朋友发红包，收到红包的小朋友会离开小明家。每个红包需要花费a元。

    2、 购买一个新礼物，每个礼物价值为b元。

    问小明最少花费多少元，才能使得所有礼物可以被剩下的小朋友平分。

    输入：第一行输入四个整数n,m,a,b（1≤n,m,a,b≤100）。
    输出最少花费。
*/

//解法
/*
   

*/

#include<iostream>
#include<vector>
using namespace std;
using std::vector;

int main()
{
    int n,m,a,b;
    while(cin>>n>>m>>a>>b){
        int j = 0; //收到红包的人数
        int i = 0; //多买了i个礼物
        int k = 1; //每个得到k个礼物
        int cost = 10000; //最大花费
        if(a==0||b==0)
        {
            cout<<0<<endl;
        }
        for(i=0;i<=100;i++){
            for(j=0;j<=100;j++){
                    if((m+i)==(k*(n-j))){
                    int temp = a*j+b*i;
                    if(temp<cost){
                        cost = temp;
                    }
                }
            }
        }
        cout<<cost<<endl;
    }
    return 0;
}
