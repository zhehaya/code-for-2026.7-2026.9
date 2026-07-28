#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
void chuli(int x1,int y1,int x2,int y2)
{
    int flag=x1*y2-y1*x2;
    if(flag>0) cout<<"LEFT";
    if(flag<0) cout<<"RIGHT";
    if(flag==0) cout<<"STRAIGHT";

}
signed main()
{cin>>T;
    while(T--)
    {
        int n;
        int a,b,c,d;
        cin>>n;
        cin>>a>>b>>c>>d;
        a=c-a;
        b=d-b;
        for(int i=3;i<=n;i++)
        {
            int nowx,nowy;
            cin>>nowx>>nowy;
            chuli(a,b,nowx-c,nowy-d);
            cout<<endl;
            a=nowx-c,b=nowy-d;
            c=nowx,d=nowy;
        }
    }

}