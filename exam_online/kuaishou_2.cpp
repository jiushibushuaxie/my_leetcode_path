#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    /**
     * 返回无重复幂因子的 N进制完美数之和的所有幂因子
     * @param R int整型 
     * @param N int整型 N进制
     * @return int整型vector
     */
    vector<int> GetPowerFactor(int R, int N) {
        // write code here
        vector<int> result;
        if(N==1){
            if(R==1) return {1};
            return {};
        }
        int up;
        long big;
        for(int i=0;i<sqrt(R/N);i++){
            for(up=0;up<sqrt(R/N);up++){
                big = (pow(N,up)-1)/(N-1)*pow(N,i);
                if(big==R){   
                    for(int j=0;j!=up;j++)
                        result.push_back(j);
                    return result;
            }
            }
            
        }
    }
};

int main()
{
    Solution s;
    int R =39;
    int N =3;
    vector<int> result = s.GetPowerFactor(R,N);
    for(auto s: result)
        cout<<s<<endl;
    return 0;
}
