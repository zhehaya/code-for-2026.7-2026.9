#include<bits/stdc++.h>
#define int long long
using namespace std;
map<pair<int,int>,int>qv;
int n;
int a;
int ans;
int m;
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
signed main()
{
    cin>>n;
    while(n--)
    {
        a=read();
        int l,flag=0;int i=0;
        while(a>0)
        {
            
            i++;           
            if(((a&1)==1)&&(flag==0)){
            flag=1;
            l=i;
           }
           //cout<< (a&1 )<<" "<<flag<<endl;
           if(((a&1)==0)&&(flag==1)) {
            flag=0;
            qv[{l,i-1}]++;//cout<<"qqa";
            ans++;
            }
            
            a>>=1;
        }
        if(flag==1) {qv[{l,i}]++;ans++;}
    }
   // cout<<ans<<"kk"<<endl;
    cin>>m;

    while(m--)
    {
        int opt;
        cin>>opt;
        cin>>a;
        for (auto [key, val] : qv) {
            int l=key.first,r=key.second;
            
        }

    }

} //
  