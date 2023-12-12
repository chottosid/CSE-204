#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int,int> &p1, pair<int,int>& p2){
    bool flag=false;
    (p1.second>=p2.second)? :flag=true;
    return flag;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;cin>>n;
    vector<pair<int,int>> v;
    while (n--)
    {
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end(),comp);
    //for(auto x:v) cout<<x.first<<" "<<x.second<<endl;
    int t=0;
    int cnt=0;
    vector<pair<int,int>> store;
    for(auto x:v){
        if(x.first>=t){
            cnt++;
            store.push_back({x.first,x.second});
            t=x.second;
        }
    }
    cout<<cnt<<endl;
    for(auto x:store){
        cout<<x.first<<" "<<x.second<<endl;
    }
}