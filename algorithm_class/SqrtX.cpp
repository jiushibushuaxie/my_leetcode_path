#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// x的平方根  牛顿迭代法
class Solution {
public:
    int mySqrt(int x) {
        double x0,x1;
        x0=x;
        x1=(x0+x/x0)/2;
        while(abs(x0-x1)>=1){
            x0=x1;
            x1=(x0+x/x0)/2;
        }
        return (int)x1;
    }
};