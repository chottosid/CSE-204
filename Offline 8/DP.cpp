#include "bits/stdc++.h"
using namespace std;

#define NMAX 100
#define WMAX 1000
vector<pair<int,int>> v(NMAX+1);
int dp[NMAX][WMAX];
vector<int> ans;

int DP(int i,int w){
    if(i==0 or w==0){
        dp[i][w]=0;
        return 0;
    }
    if(dp[i][w]!=-1) return dp[i][w];
    if(w>=v[i].first){
        dp[i][w]=max(DP(i-1,w),DP(i-1,w-v[i].first)+v[i].second);
    }
    else{
        dp[i][w]=DP(i-1,w);
    }
    return dp[i][w];
}
void print(int n,int w){
    if(n==0) return;
    if(dp[n][w]!=dp[n-1][w]){
        ans.push_back(v[n].first);
        print(n-1,w-v[n].first);
    }
    else print(n-1,w);
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    v.clear();
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i].first>>v[i].second;
    }
    int w;cin>>w;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++) dp[i][j]=-1;
    }
    DP(n,w);
    cout<<dp[n][w]<<endl;
    print(n,w);
    reverse(ans.begin(),ans.end());
    for(auto x:ans)cout<<x<<" ";
}