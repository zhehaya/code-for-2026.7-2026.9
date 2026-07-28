#include<bits/stdc++.h>
#define N 5114514
using namespace std;
int n,m,s;
vector<int>tree[N];
bool vis[N];
namespace EUL{
    struct depid{
        int depth,id;
        bool operator<(const depid& otherdepid)const
        {
            return depth<otherdepid.depth;
        }
    }euler[N];//欧拉序，记录每一个的深度和id
    int euler_fir[N];//标记第一次出现在第几个 
    int eulercnt=0;  
    void dfs(int u,int dep)
    {
        if(vis[u]) return;
        vis[u]=1;
        euler[++eulercnt]={dep,u};
        euler_fir[u]=eulercnt;
        for(int v:tree[u])
        {
            dfs(v,dep+1);
            euler[++eulercnt]={dep,u};
        }
    }
}
namespace ST{
    EUL::depid st[N][20];
    int log2[N];
    void log_calc(){
        //log2为小于等于i的最大2^val的val值,或者为二进制位数的多少（用这个来理解预处理）
        for(int i=2;i<=N-2;i++)
            log2[i]=log2[i>>1]+1;
    }
    void st_calc(){
        for(int i=1;i<=EUL::eulercnt;i++) st[i][0]=EUL::euler[i];
        for(int i=1;i<=log2[EUL::eulercnt];i++)
            for(int j=1;j<=EUL::eulercnt-(1<<i)+1;j++)
                st[j][i]=min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
    }
    EUL::depid querymin(int l,int r)
    {
        int lognum=log2[r-l+1];
        return min(st[l][lognum],st[r-(1<<lognum)+1][lognum]);
    }
}
namespace LCA{
   int lca(int u,int v)
   {
    return ST::querymin(min(EUL::euler_fir[u],EUL::euler_fir[v]),max(EUL::euler_fir[u],EUL::euler_fir[v])).id;
   } 
}
void precalc()
{
    EUL::dfs(s,1);
    ST::log_calc();
    ST::st_calc();
}
int main()
{
 cin>>n>>m>>s;
 for(int i=1;i<n;i++) {
    int x,y;
    cin>>x>>y;
    tree[x].push_back(y);
    tree[y].push_back(x);
 }
 precalc();
 while(m--){
    int a,b;
    cin>>a>>b;
    cout<<LCA::lca(a,b)<<endl;
 }
 
}