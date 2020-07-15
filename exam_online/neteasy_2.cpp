#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;

int main() {
    int T; //T组数据
    int N,M;  //每组数据有N个整数1-N，M个操作数
    cin>>T;
    while(T){
        cin>>N>>M;
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


        vector<int> nums(N,1);
        for(int i=0;i!=M;i++){
            for(int j=0;j!=data[i].size();j++){
                if(data[i][0]==3){
                    cout<<nums[data[i][1]]<<endl;
                }
                if(data[i][0]==1){
                    int temp1 = nums[data[i][1]];
                    int temp2 = nums[data[i][2]];
                    nums[data[i][1]] =temp1 + temp2;
                    nums[data[i][2]] = nums[data[i][1]];
                }
                if(data[i][0]==2){
                    nums[data[i][1]] = 1;
                }
            }
        }

        data.clear();
        --T;
    }
    return 0;
}