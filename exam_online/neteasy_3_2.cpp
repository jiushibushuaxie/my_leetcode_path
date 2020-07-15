#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    int t;
    while(t)
    {
        int n;
        cin>>n;
        vector<int> vec1(n);
        vector<int> vec2(n);
        for(int i=0; i<n; i++)
        {
            cin>>vec1[i];
        }
        int min = 100;
        int res = 0;
        for(int i=0; i<n; i++)
        {
            cin>>vec2[i];
            if(i%2 == 0 && vec2[i] < min)
            {
                min = vec2[i];
            }
            res += vec2[i];
        }
        if(n%2 == 1)
        {
            res += min;
        }
        cout<<res<<endl;
        t--;
    }
 
    return 0;
}