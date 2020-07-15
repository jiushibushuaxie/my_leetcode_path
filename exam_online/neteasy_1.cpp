#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;

// 题目
// https://www.nowcoder.com/discuss/405887?type=post&order=create&pos=&page=1

int main() {
    int T; //T组数据
    cin>>T;
    while(T){
        int M,L;  //MXM矩阵， L刀长
        cin>>M>>L;
        vector<vector<int>> data;
        for(int k=0;k!=M;k++){
            int a;
            vector<int> b;
            while(cin>>a){
                b.push_back(a);
                if(cin.get() == '\n')
                break;
            }
            data.push_back(b);
        }
        int X,Y;
        cin>>X>>Y; //主角的位置

        vector<int> Xs;
        vector<int> Ys;
        vector<int> dao;
        int c = 0;
        for(int i=0;i!=M;i++){
            for(int j=0;j!=M;j++){
                if(data[i][j]!=0){
                Xs.push_back(i);
                Ys.push_back(j);
                dao.push_back(data[i][j]);
                ++c;
                }
            }
        }

        vector<pair<double,int>> dst(Xs.size());  //定义pair必须要给定大小
        for(int r=0;r!=Xs.size();r++){
            double temp = sqrt((Xs[r] - X)*(Xs[r] - X) + (Ys[r] - Y)*(Ys[r] - Y));
            dst[r].first = temp;
            dst[r].second = dao[r];
        } 


        sort(dst.begin(), dst.end(), [&](pair<double, int> a, pair<double, int> b){return a.first < b.first;});
        for(int s=0; s!=Xs.size();s++){
            if(dst[s].first<=L){
                L += dst[s].second;
            }
        }

        cout<<L<<endl;
        data.clear();
        --T;
    }
}
