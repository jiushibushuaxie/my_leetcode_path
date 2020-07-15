#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;

int main() {
    int a = 5;
    const int *p = &a;
    cout<<*p<<endl;
    double b = sqrt(4);
    cout<<b<<endl;

    vector<pair<double, int>> ar(1);
    ar[0].first = 1.0;
    ar[0].second = 3;
    cout<<ar[0].second<<endl;

    // vector<int> aa;
    // aa[2] = 4;    //不能这样定义，aa没有指明大小
    vector<int> aa(3);
    aa[2] = 4;    //不能这样定义，aa没有指明大小

    cout<<aa[2]<<endl;
}
