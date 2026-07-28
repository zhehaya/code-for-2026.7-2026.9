#include<bits/stdc++.h>
#define int long long
#define INF 10000000000000000
using namespace std;
int T,n,m,a[214514],b[214514];
int suma[214514],dp[214514][2];
signed main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        int ans=-INF;
        for(int i=1;i<=n;i++) 
        {
            cin>>a[i];
            suma[i]=suma[i-1]+a[i];
        }
        for(int i=1;i<=m;i++) cin>>b[i];
        sort(b+1,b+1+m);
        dp[0][1]=0,dp[0][0]=-INF;//1为第奇数个，0为第偶数个
        int max1=0,max0=0;
        for(int i=1;i<=m;i++)
        {
            max0+=(suma[b[i]]-suma[b[i-1]]);
            max1+=(suma[b[i-1]]-suma[b[i]]);
            dp[b[i]][0]=max0;
            dp[b[i]][1]=max(-suma[b[i]],max1);
            max0=max(max0,dp[b[i]][1]);
            max1=max(max1,dp[b[i]][0]);
            int nowsum=suma[n]-suma[b[i]];
            ans=max(ans,dp[b[i]][1]+nowsum);
        }
        cout<<max(suma[n],ans)<<endl;
        
    }
}