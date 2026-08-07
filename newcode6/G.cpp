#include<bits/stdc++.h>
#define N 214514
using namespace std;
int T;
int n,m,k;
int te[N];//特殊点
int iste[N];//判断特殊点
int dp[N][4];//dp[i][j]从第j个边走的alice胜利(1)还是失败(0)
int edge[N][4][2];//边 [0]记录到哪里，[1]记录是去的点对应的哪一条边
int edgecnt[N];//记录边的数量
int iswin[N];//代表是否先手胜
int ansc;
void SPFA_G(){//基于SPFA的dp
    queue<int>spfa;
    for(int i=1;i<=k;i++)
        spfa.push(te[i]);
    while(!spfa.empty())
    {
        int nownode=spfa.front();
        spfa.pop();
        //cout<<nownode<<"t"<<endl;
        for(int i=1;i<=edgecnt[nownode];i++)
        {
            int v=edge[nownode][i][0],vid=edge[nownode][i][1];
            //if(v==1) cout<<"zhi";
            if(dp[v][vid]) continue;
            int sumyes=0;
            for(int j=1;j<=edgecnt[nownode];j++) if(j!=i) {//cout<<j<<":"<<dp[nownode][j]<<endl;
                sumyes+=dp[nownode][j];}
            //cout<<nownode<<"<-"<<v<<" "<<vid<<" "<<sumyes<<endl;
            if(iste[nownode] || (sumyes>=2)){
                dp[v][vid]=1;
                //cout<<v<<"$"<<vid<<endl;
                spfa.push(v);
                if((!iswin[v])&&(!iste[v])){
                    iswin[v]=1;
                    ansc++;
                    //cout<<v<<"agfguiafggr"<<endl;
                }
            }
        }
    }
}
int main()
{
cin>>T;
while(T--)
{
    
cin>>n>>m>>k;

for(int i=0;i<=n+1;i++)
{
    dp[i][0]=dp[i][1]=dp[i][2]=dp[i][3]=0;
    iste[i]=te[i]=0;
    edgecnt[i]=0;
    iswin[i]=0;
    //edge预处理吗？？？？
}
ansc=0;
    
while(m--)
{
    int u,v;
    cin>>u>>v;
    edgecnt[u]++;
    edgecnt[v]++;
    edge[u][edgecnt[u]][0]=v;
    edge[u][edgecnt[u]][1]=edgecnt[v];
    edge[v][edgecnt[v]][0]=u;
    edge[v][edgecnt[v]][1]=edgecnt[u];
}
for(int i=1;i<=k;i++)
{
    int tenode;
    cin>>tenode;
    te[i]=tenode;
    iste[tenode]=1;
}
//cout<<"begin";
SPFA_G();
//cout<<"end"<<endl;
cout<<ansc<<endl;
for(int i=1;i<=n;i++)
    if(iswin[i]) cout<<i<<" ";
   
cout<<endl;
}

}