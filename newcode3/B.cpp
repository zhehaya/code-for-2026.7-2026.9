#include<bits/stdc++.h>
#define N 1145141
#define int long long
using namespace std;

const int p=998244353;

int T;

long long fast_pow(long long a,long long k)
{
    long long res=1;
    while(k>0)
    {
        if(k&1) res=(res*a)%p;
        a=(a*a)%p;
        k>>=1;
    }
    return res;
}

inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
        x=x*10+ch-'0',ch=getchar();
    return x*f;
}

int invv(int x)
{
    return fast_pow(x,p-2)%p;
}

int lie[N];

int C(int sh,int xi)
{
    if(xi<0||xi>sh)
        return 0;
    return lie[sh]*invv(lie[xi])%p*invv(lie[sh-xi])%p;
}

int n,m,c,a,b;


int chuli(int kk)
{
    return n%p*C(m,kk)%p*invv(m)%p;
}


signed main()
{
    lie[0]=1;
    for(int i=1;i<=2000000;i++)
        lie[i]=lie[i-1]*i%p;

    T=read();

    while(T--)
    {
        n=read(),m=read(),c=read(),a=read(),b=read();

        if(m<n||(m-n)%c!=0)
        {
            printf("0\n");
        }
        else
        {
            int k=(m-n)/c;

            if(k>m)
            {
                printf("0\n");
                continue;
            }

            int ans=chuli(k);

            // 概率部分:
            // a^k*(b-a)^(m-k)/b^m

            ans=ans*fast_pow(a,k)%p;
            ans=ans*fast_pow(b-a,m-k)%p;
            ans=ans*invv(fast_pow(b,m))%p;

            cout<<ans<<endl;
        }
    }
}