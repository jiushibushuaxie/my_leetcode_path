#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <set>

using namespace std;

void generate(int n,int m,long &count, vector<vector<int>>& mark){
    int N = mark.size();
    int M = mark[0].size();
    if(n>=N&&m>=M){
        count++;
        return;
    }
   
    if(n<N&&m<M&&mark[n][m]==0){
        m = m+1;
        if(m==M){
            m=0;
            n = n+1;
            if(n==N){
                m=M;
            }
        }
        generate(n,m,count,mark);
    }
    if(n<N&&m<M&&mark[n][m]==1){
        int a = n;
        int b = m;
        vector<vector<int>> tmp_mark = mark;
        if(n>0) mark[n-1][m] = 0;
        if(n<N-1) mark[n+1][m] = 0;
        if(m>0) mark[n][m-1] = 0;
        if(m<M-1) mark[n][m+1] = 0;
        m = m+1;
        if(m==M){
            m=0;
            n = n+1;
            if(n==N){
                m=M;
            }
        }
        generate(n,m,count,mark);
        mark = tmp_mark;
        mark[a][b] = 0;
        generate(n,m,count,mark);

    }
}

int main() {

    int N,M;
    cin>>N>>M;
    if(N==0||M==0) return 0;
    vector<vector<int>> mark(N,vector<int>(M,0));
    int s;
    int plus = 0;
    for(int n=0;n<N;++n){
        for(int m=0;m<M;m++){
            cin>>s;
            mark[n][m] = s;
        }
    }

    long count = 0;
    generate(0,0,count,mark);

    cout<<count%100000000<<endl;

    return 0;
}