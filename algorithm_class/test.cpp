#include <iostream>

using namespace std;

class A{
    int b = 0;
    int a(){return 0;};
};

int main()
{
    
    int a[]= {1,2,3};
    int *p = a;
    cout<<*p<<endl;

    {int * c = new int[121];
    c[0] = 2;
    cout << c[0]<<endl;
    }

    cout<<sizeof(A)<<endl;

    return 0;
}


