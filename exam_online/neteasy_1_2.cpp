#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

//作为sort的第三个参数 用于pair
bool compare(pair<int, int>& p1, pair<int, int>& p2)
{
    if(p1.first == p2.first)
    {
        return p1.second < p2.second;
    }
    return p1.first < p2.first;
}

// bool compare(pair<int,int> &p1, pair<int, int> &p2){
//     if(p1.first == p2.first)
//         return p1.second<p2.second;
//     return p1.first<p2.first;
// }

//给定矩阵，矩阵大小，刀长，主角位置x,y
void getlength(vector<vector<int>>& vec, int m, int& l, int x, int y)
{
    vector<pair<int, int>> res(m*m);
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<m; j++)
        {
            int key = (i-x)*(i-x)+(j-y)*(j-y);
            res[i*m+j].first = key;
            res[i*m+j].second = vec[i][j];
        }
    }
    sort(res.begin(), res.end(), compare);
    for(int i=0; i<res.size(); i++)
    {
        if(l*l >= res[i].first)
        {
            l += res[i].second;
        }
        else
        {
            break;
        }
    }
}
 
int main()
{
    int t;
    while(cin>>t)
    {
        while(t)
        {
            int m, l;
            cin>>m>>l;
            vector<vector<int> > vec(m, vector<int>(m));  //指定大小后就不用push_back了
            for(int i=0; i<m; i++)
            {
                for(int j=0; j<m; j++)
                {
                    cin>>vec[i][j];
                }
            }
            int x, y;
            cin>>x>>y;
            getlength(vec, m, l, x, y);
            cout<<l<<endl;
            t--;
        }
         
    }
}