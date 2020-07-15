#include <iostream>
using namespace std;

typedef long long ll;
//x底数 n幂 m：对m取余
ll quick_pow(ll x,ll n,ll m){
	ll res = 1;
	while(n > 0){
		if(n & 1)	res = res * x % m;
		x = x * x % m;
		n >>= 1;        //相当于n=n/2.详情请参考位移运算符。
	}
	return res;
} 



ll QuickRow(ll a, ll b){
    ll res = 1;
    while(b>0){
        if(b&1) {   //判断b的末尾是否为1
            res = res*a;
        }
        a *= a;
        b >>=1; 
    }
    return res;
}