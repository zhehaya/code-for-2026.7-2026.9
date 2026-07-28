#include<bits/stdc++.h>
#define int long long
#define N 1145
using namespace std;
int val[N][N];
int n,m;
int dp[N][N];//悬线长
int l[N][N],r[N][N];
int ans=0;
stack<int>st;//存下标
signed main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            {
                char inn;
                cin>>inn;
                if(inn=='*') val[i][j]=0;
                else val[i][j]=1;//1为可以填的
            }
    for(int i=1;i<=n;i++)
        {
            dp[i][0]=-1,dp[i][m+1]=-1;
            for(int j=1;j<=m;j++)
                if(val[i][j]) dp[i][j]=dp[i-1][j]+1;//第一遍求悬线长
            st.push(0);
            for(int j=1;j<=m;j++)
            {
                while(dp[i][st.top()]>=dp[i][j]) st.pop();
                l[i][j]=j-st.top();
                st.push(j);
            }//第二遍求l
            while(!st.empty()) st.pop();
            st.push(m+1);
            for(int j=m;j>=1;j--)
           {//如有必要必须加上
                while(dp[i][st.top()]>dp[i][j]) st.pop();
                r[i][j]=st.top()-j;//第二遍求r和ans
                //ans+=(dp[i][j]*l[i][j]*r[i][j]);
                st.push(j); ans+=(dp[i][j]*l[i][j]*r[i][j]);
            }
                
        }
        cout<<ans;
    
}