#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<long> Ax(n,0);
    vector<long> Ay(n,0);
    vector<long> Bx(n,0);
    vector<long> By(n,0);
    for(int i =0;i<n;i++){
        long aix,aiy;
        cin>>aix>>aiy;
        Ax[i] = aix;
        Ay[i] = aiy;
    }
    for(int i =0;i<n;i++){
        long bix,biy;
        cin>>bix>>biy;
        Bx[i] = bix;
        By[i] = biy;
    }
    long result = 0x3f3f3f3f;
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            long temp = (Ax[i]-Bx[j])*(Ax[i]-Bx[j]) + (Ay[i] - By[j])*(Ay[i] - By[j]);
            if(result>temp) result =temp;
        }  
    }
    double ans =sqrt(result);
    printf("%.3f\n",ans);

}
