#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
int n,m;
signed main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        if(m>=(n*(n-1)/2)) cout<<0<<endl;
        else if(m>=n-1)
            cout<<(n*(n-1)/2)-m<<endl;
        else{
            cout<<(m*(m+1)/2)-m<<endl;
        }

    }
}