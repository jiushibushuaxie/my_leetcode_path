//111111111111111
/*
输入数据包括多组。
每组数据一行,每行的第一个整数为整数的个数n(1 <= n <= 100), n为0的时候结束输入。
接下来n个正整数,即需要求和的每个正整数。

输入
4 1 2 3 4
5 1 2 3 4 5
0

输出
10
15
*/
#include<iostream>
using namespace std;
int main(){
    int n;
    int a,b=0;
    while(cin>>n){
        if(!n)
            break;
        while(n--){   
            cin>>a;
            b+=a;
        }
        cout<<b<<endl;
        b = 0;
    }
}

//222222222222
/*
输入数据有多组, 每行表示一组输入数据。
每行不定有n个整数，空格隔开。(1 <= n <= 100)。

输入
1 2 3
4 5
0 0 0 0 0

输出
6
9
0
*/

#include<iostream>
using namespace std;
 
int main()
{
    int n;
    int sum  = 0 ;
    while(cin >> n ){
        sum += n;
        if(cin.get() == '\n') {
            cout << sum << endl;
            sum = 0;
        }
    }                       
    return 0 ;
}

//33333333333333
/*
输入有两行，第一行n
第二行是n个空格隔开的字符串

输出一行排序后的字符串，空格隔开，无结尾空格

输入
5
c d a bb e

输出
a bb c d e
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<string> str;
    for(int i = 0;i!=n;i++){
        string a;
        cin>>a;
        str.push_back(a);
    }
    sort(str.begin(),str.end());
    for(int i = 0;i<n;i++){
        cout<<str[i]<<" ";
    }
    return 0;
}

//444444444444
/*
多个测试用例，每个测试用例一行。
每行通过空格隔开，有n个字符，n＜100

对于每组测试用例，输出一行排序过的字符串，每个字符串通过空格隔开

输入
a c bb
f dddd
nowcoder

输出
a bb c
dddd f
nowcoder
*/

#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int n;
    string a;
    vector<string> str;
    while(cin>>a){
        str.push_back(a);
        if (cin.get()=='\n'){
            sort(str.begin(),str.end());
            for(int i = 0;i!=str.size();i++){
            cout<<str[i]<<" ";
            }
            cout<<endl;
            str.clear();
        }
    }
    return 0;
}

//5555555555555555
/*
多个测试用例，每个测试用例一行。
每行通过,隔开，有n个字符，n＜100

对于每组测试用例，输出一行排序过的字符串，每个字符串通过空格隔开

输入
a,c,bb
f,dddd
nowcoder

输出
a,bb,c
dddd,f
nowcoder
*/
//自己重写的
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string s;
    vector<string> str;
    while(getline(cin,s)){
        stringstream a(s);
        string b;
        while(getline(a,b,',')){
            str.push_back(b);
        }
        sort(str.begin(),str.end());
        cout<<str[0];
        for(int i=1;i!=str.size();++i){
            cout<<","<<str[i];
        }
        cout<<endl;
        str.clear();
    }
    return 0;
}



#include<vector>
#include<algorithm>
#include <iostream> 
#include<string>
#include<sstream>
using namespace std;
int main()
{
	string s;
	vector<string> str;
	while (getline(cin, s)) {
		string b;
		stringstream a(s);      //a(s) 表示a是s的一个拷贝
        //getline(a,b,‘c’)
        //第三个参数是指定结束符，有一个默认值，为’\n’
		while (getline(a, b, ','))   //一定是单引号
			str.push_back(b);

		sort(str.begin(), str.end());
		cout << str[0];
		int n = str.size();
		for (int i = 1; i < n; ++i) {
			cout << ',' << str[i];
		}
		cout << endl;
		str.clear();
	}
	return 0;
}