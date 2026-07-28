#include<bits/stdc++.h>
using namespace std;
int T;
int n,x,y;
int a[214514];
int main()
{
cin>>T;
while(T--)
{
    cin>>n>>x>>y;
    int ggc=__gcd(x,y);
    int flag=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        int c=abs(a[i]-i);
        if(c%ggc!=0) 
            flag=0;
    }
    if(flag) cout<<"yes"<<endl;
    else cout<<"NO"<<endl;
}
}