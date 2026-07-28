#include<bits/stdc++.h>
#define ll long long
#define N 114514
using namespace std;
int n;
ll ans;
int b[N];//桶排
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
    while(ch>='0' && ch<='9')
        x=x*10+ch-'0',ch=getchar();
    return x*f;
}
queue<ll>pre,ope;
int main()
{
    int n;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        x=read();
        b[x]++;
    }
    for(int i=1;i<=100000;i++) if(b[i]) {
        for(int j=1;j<=b[i];j++)
        pre.push(i);}
    for(int i=1;i<=n-1;i++)
    {
        if(ope.empty())//拿出两个合并后push到ope
        {
            ll val=pre.front();pre.pop();
            val+=pre.front();pre.pop();
            ope.push(val);ans+=val;//cout<<val<<"1"<<endl;
        }
        else if(pre.empty()) {
            ll val=ope.front();ope.pop();
            val+=ope.front();ope.pop();
            ope.push(val);ans+=val;//cout<<val<<"2"<<endl;
        }
        else{
            ll val=0;
            if(pre.front()<=ope.front()){
                val=pre.front();pre.pop();
            }else{
                val=ope.front();ope.pop();
            }
             if(ope.empty())//拿出两个合并后push到ope
        {
            val+=pre.front();pre.pop();
            ope.push(val);ans+=val;
        }
        else if(pre.empty()) {
            val+=ope.front();ope.pop();
            ope.push(val);ans+=val;
        }
            else{
                if(pre.front()<=ope.front()){
                val+=pre.front();pre.pop();
            }else{
                val+=ope.front();ope.pop();
            }
            ope.push(val);ans+=val;
            }
            //cout<<val<<"3"<<endl;
        }
    }
    printf("%lld",ans);
}
//需要快读才能过
