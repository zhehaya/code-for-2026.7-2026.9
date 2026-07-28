#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll fac[2000009];
ll p=1e9+7;
ll n,m,k;
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
    cin>>n>>m>>k;
    if(n>k+m) cout<<0;
    else{
    ll ans=C(n+m,n);
    if(n>=k+1) ans=(ans+p-C(n+m,k+1+m))%p;
    cout<<ans%p;
    }
    
}
//第一次bug出在有一处忘记处理mod p
//第二次出bug在于忘记N+M才是数组最终大小下界
//第三次在于忘记考虑减法要先加p
//第四次忘记特判不成立的情况