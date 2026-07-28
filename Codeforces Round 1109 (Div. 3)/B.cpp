#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
int n;
int a[214514];
signed main()
{
cin>>T;
while(T--)
{
    cin>>n;
    int lst=0,flag=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]+=lst;
        if(flag==1)
        {
        if(a[i]>a[i-1]){
            lst=a[i]-(a[i-1]+1);
            a[i]=a[i-1]+1;
        }else flag=0;
        }
        
    }
    if(flag) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
}
}