#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;cin>>n;
    vector<tuple<int,int,int>> v;
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        int t,p;
        cin>>t>>p;
        mx=max(t,mx);
        v.push_back(make_tuple(p,t,i));
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    vector<int> persons;
    bool time[mx+1]={false};
    int ans=0;
    for(auto x:v){
        int a=get<1>(x);
        for(int i=a;i>=0;i--){
            if(time[i]==false){
                time[i]=true;
                persons.push_back(get<2>(x));
                ans+=get<0>(x);
                break;
            }
        }
    }
    for(auto x:persons) cout<<x<<" ";
    cout<<endl<<"Profit: "<<ans<<endl;
}