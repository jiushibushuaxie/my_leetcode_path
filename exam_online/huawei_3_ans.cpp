#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_map>

using namespace std;
typedef long long ll;
const int maxn=505;
ll m,k;
ll a[maxn];
ll ans;
 
bool check(ll x)
{
    ll now=0;
    int t=0;
    for(int i=0;i<m;i++)
    {
        if(now>=x)
        {
            t++;
            now=0;
            i--;
        }
        else
        {
            now+=a[i];
        }
    }
    if(now>=x)
    {
        t++;
    }
    if(t>=k)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//[  )
int main()
{
    cin>>m>>k;
    for(int i=0;i<m;i++)
    {
        cin>>a[i];
        ans+=a[i];
    }
    if(k==1)
    {
        for(int i=0;i<m;i++)
        {
            cout<<a[i]<<' ';
        }
        cout<<endl;
        return 0;
    }
 
 
    ll l=0,r=ans;
 
    while(l<r)
    {
        ll mid=(l+r)/2;
        if(check(mid))
        {
            l=mid+1;
        }
        else
        {
            r=mid;
        }
    }
    ll d=l-1;
    ll now=0;
    vector<ll> v;
    int num=1;
    for(int i=0;i<m;i++)
    {
        now+=a[i];
        if(now>=d)
        {
            v.push_back(i);
            now=0;
            num++;
        }
        if(num>=k)
        {
            break;
        }
    }
    int cnt=0;
    for(int i=0;i<m;i++)
    {
 
        cout<<a[i]<<" ";
        if(i==v[cnt])
        {
            cnt++;
            cout<<"/ ";
        }
    }
    cout<<endl;
 
}