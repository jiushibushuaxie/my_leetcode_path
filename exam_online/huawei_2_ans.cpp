#include <bits/stdc++.h>
using namespace std;
 
vector<int> v;
vector<int> ans;
int len;
int flag=0;
 
bool check()
{
    if(flag==-1)
    {
        return false;
    }
    if(v.size()==0)
    {
        return false;
    }
    len=v[v.size()-1];
    if(v.size()==len+flag+1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool be=false;

int main()
{
    int now;
 
 
    while(cin>>hex>>now)
    {
        if(now==90)
        {
            be=true;
        }
        if(!be)
        {
            continue;
        }
        if(now==90)
        {
            if(check())
            {
                if(v.size()!=0)
                    ans.push_back(90);
                for(int i=0;i<v.size();i++)
                {
 
                    ans.push_back(v[i]);
                }
            }
            flag=0;
            v.clear();
        }
        else
        {
            v.push_back(now);
            int last=v.size()-1;
            if(v[last-1]==91&&v[last]==186)
            {
                flag++;
            }
            else if(v[last-1]==91&&v[last]==187)
            {
                flag++;
            }
            else if(v[last-1]==91)
            {
                flag=-1;
            }
        }
    }
    for(int i=0;i<ans.size();i++)
    {
        printf("%02x ",ans[i]);
    }
    if(ans.size()!=0)
        printf("5a\n");
}