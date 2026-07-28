#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll fac[2000009];
ll p=20100403;
ll n,m;
ll fast_pow(ll a,ll b)
{
    ll res=1;
    while(b>0)
    {
        if(b&1) res=(res*a)%p;
        a=(a*a)%p;
        b>>=1;
    }
    return res%p;
}
ll inv(ll a){
    return fast_pow(a,p-2);
}
ll C(ll all,ll sel)
{
    ll und=inv((fac[sel]*fac[all-sel])%p),onn=fac[all];
    //cout<<onn;
    return (und*onn)%p;
}
int main()
{
    //pre
    fac[0]=1;
    for(ll i=1;i<=2000002;i++)
        fac[i]=(fac[i-1]*i)%p;
    //cout<<fac[5];    
    cin>>m>>n;
    if(n>m) cout<<0;
    else{
    ll ans=C(n+m,n);
    if(n>=1) ans=(ans+p-C(n+m,1+m))%p;
    cout<<ans%p;
    }
    
}
//把AT_abc205_e中的k命为0，n,m输入顺序替换即可