
//问题描述
/*
    小Q得到一个神奇的数列: 1, 12, 123,...12345678910,1234567891011...。
    并且小Q对于能否被3整除这个性质很感兴趣。
    小Q现在希望你能帮他计算一下从数列的第l个到第r个(包含端点)有多少个数可以被3整除。 
输入：
    输入包括两个整数l和r(1 <= l <= r <= 1e9), 表示要求解的区间两端。

输出描述:
    输出一个整数, 表示区间内能被3整除的数字个数。

示例1
输入
    2 5

输出
    3

    12, 123, 1234, 12345...
    其中12, 123, 12345能被3整除。
*/

//解法
/*
    找下规律即可  第2第3个数可以被3整除，循环
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;

int main() {
    int n;
    int m;
    int count=0;
    cin>>n>>m;
    if(n>m) cout<<0<<endl;
    for(int i=n;i<m;++i){
        if(i%3==1) ++count;
    }
    cout<<m-n-count+1<<endl;
}