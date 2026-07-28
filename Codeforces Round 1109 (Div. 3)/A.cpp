#include<bits/stdc++.h>
using namespace std;
int T;
int n;
string s;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        cin>>s;
        int len=0,ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='*'){
            ans=max(ans,(int)ceil((double)len/2));
            len=0;
            }else len++;
        }ans=max(ans,(int)ceil((double)len/2));
        cout<<ans<<endl;
    }
}