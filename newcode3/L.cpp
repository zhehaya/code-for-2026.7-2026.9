#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m;
int too[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
void dfs(int x,int y,vector<vector<int>> &h,vector<vector<int>> &isdfs,vector<vector<int>> &dp)
{
    if(isdfs[x][y]) return;
    bool flag=0;
    for(int i=0;i<=3;i++)
    {
        int tox=x+too[i][0],toy=y+too[i][1];
        if (1<=tox && tox<=n && 1<=toy && toy<=m && h[tox][toy]>h[x][y])
        {
            dfs(tox,toy,h,isdfs,dp);
            flag|=dp[tox][toy];
        }
    }
    dp[x][y]=!flag;
    isdfs[x][y]=1;
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
    while(ch>='0' && ch<='9')
        x=x*10+ch-'0',ch=getchar();
    return x*f;
}
signed main()
{
    T=read();
    while(T--)
    {
        n=read();
        m=read();
        vector<vector<int>>h(n+1,vector<int>(m+1));
        vector<vector<int>>isdfs(n+1,vector<int>(m+1,0));
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                isdfs[i][j]=0;
                h[i][j]=read();
            }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(!isdfs[i][j]) dfs(i,j,h,isdfs,dp);
        int q;
        q=read();
        while(q--)
        {
            int r,c;
            r=read(),c=read();
            if(dp[r][c])printf("Second\n");
            else printf("First\n");
        }
    }
}