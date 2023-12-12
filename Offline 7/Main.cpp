#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v;
int merge(int arr[],int store[],int l,int r){
    int m=(r+l)/2+1;
    int i=l,j=m,k=l;
    int ans=0;
    while(i<m and j<=r){
        if(arr[i]<=arr[j]) {
            store[k]=arr[i];
            k++;i++;
        }
        else{
            store[k]=arr[j];
            ans+=(m-i);
            for(int x=i;x<m;x++) v.push_back({arr[x],arr[j]});
            k++;j++;
        }
    }
    while(i<m)
    {
        store[k]=arr[i];
        k++;i++;
    }
    while(j<=r)
    {
        store[k]=arr[j];
        i++;j++;
    }
    for(int i=l;i<=r;i++) arr[i]=store[i];
    return ans;
}
int recurse(int arr[],int store[],int l,int r){
    if(l>=r) return 0;
    int mid=(l+r)/2;
    return recurse(arr,store,l,mid)+recurse(arr,store,mid+1,r)+merge(arr,store,l,r);
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int store[n]={0};
    int ans=recurse(arr,store,0,n-1);
    cout<<"The number of inversion are: "<<ans<<endl;
    cout<<"The pairs are: "<<endl;
    for(auto x:v) cout<<"("<<x.first<<","<<x.second<<")\n";
}