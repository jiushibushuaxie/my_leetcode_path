//问题描述
/*
    抽卡是一类类似于博弈的游戏。现在有一种抽卡方式，描述如下：

    初始你只有一次抽卡机会。每次抽卡浪费一次抽卡机会，获得一张卡片。
    这张卡片上有两个数字，第一个数字代表你能获得的钱，第二个数字代表你能获得的额外抽卡次数。额外的抽卡次数是可以累计的。

    现在，你知道了卡片的数量，所有的卡片上的数字，以及所有卡片的顺序。你只需要安排一种抽卡顺序，使得你能获得钱数最多。

    输入：
    第一个行一个数n,代表卡片的数量。 
    接下来n行，每行用两个数ai,bi描述一张卡片。ai表示抽这张卡能获得的钱数，bi表示抽这张卡能获得的额外抽卡次数。

    输出：
    一行一个数，代表你能获得的最多钱数。
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

int main()
{
    int n; //卡片数量
    cin>>n;
    vector<int> money{n}; //钱数
    vector<int> times{n}; //抽卡次数
    int all_money = 0;  //总钱数
    for(int i=0;i<n;i++){
        cin>>money[i]>>times[i];
        all_money = all_money + money[i];
    }

    cout<<all_money<<endl;

    return 0;
}
