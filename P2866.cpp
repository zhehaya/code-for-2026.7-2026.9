#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int ans,h[214514];
stack<pair<int,int>>st;
signed main()
{
cin>>n;
for(int i=1;i<=n;i++)
    cin>>h[i];
st.push({1145141111,n+1});
st.push({h[n],n});
for(int i=n-1;i>=1;i--)
{
    while(!st.empty()&&st.top().first<h[i]){
        st.pop();
    }
    ans+=(st.top().second-i-1);
    st.push({h[i],i});
}
cout<<ans;
}