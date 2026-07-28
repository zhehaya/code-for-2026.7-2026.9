#include<bits/stdc++.h>
#define N 214514
#define int long long
using namespace std;
int T;
int a[N],suma[N];
int n,k;
signed main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++) 
            cin>>a[i];
        sort(a+1,a+1+n);
        for(int i=1;i<=n;i++)  suma[i]=suma[i-1]+a[i];
        int prek=k/2;
        int presum=suma[prek];
        if(k%2)
        {
            int ans=-1;
            for(int i=prek+1;i<=n-prek;i++)//枚举中位数
            {
                int nowans=(k*a[i])-presum-a[i]-(suma[i+prek]-suma[i])+suma[n];
                ans=max(ans,nowans);
            }
            cout<<ans<<endl;
        }
        else{
            int ans=-1;
            for(int i=prek+1;i<=n-prek+1;i++)
            {
                int nowans=(a[i]+a[i-1])*prek;
                nowans-=(presum-a[prek]+suma[i+prek-1]-suma[i-2]);
                nowans+=suma[n];
                ans=max(ans,nowans);
            }
            cout<<ans<<endl;
        }
    }
}