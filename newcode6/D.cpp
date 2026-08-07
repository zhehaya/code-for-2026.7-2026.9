#include<bits/stdc++.h>
#define N 514514
#define int long long
using namespace std;
const int INF=1145141191911;
int T,n,m,k;
int dis[N][2];//dis[i][0]为偶数最小dis,dis[i][1]为奇数最小dis
vector<int>edge[N];
void SPFA_D()
{
    queue<int>spfa;
    dis[1][0]=0;
    spfa.push(1);
    while(!spfa.empty())
    {
        int nownode=spfa.front();
        spfa.pop();
        for(int i:edge[nownode]){
            int flag=0;
            if(dis[nownode][0]+1<dis[i][1]){
                dis[i][1]=dis[nownode][0]+1;
                flag=1;
            }if(dis[nownode][1]+1<dis[i][0]){
                dis[i][0]=dis[nownode][1]+1;flag=1;
            }if(flag){
                spfa.push(i);
            }
        }
    }
    
}
signed main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++) {
            edge[i].clear();dis[i][1]=dis[i][0]=INF;}
        while(m--)
        {
            int u,v;
            cin>>u>>v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        
        SPFA_D();
       // for(int i=1;i<=n;i++) cout<<dis[i][0]<<" "<<dis[i][1]<<endl;
        cout<<0<<" ";
        for(int i=2;i<=n;i++)
        {
            if(k%2){//奇数偶数均可以胜任
                if(min(dis[i][0],dis[i][1])<1100000000)
                {
                    int ans=INF;
                    //偶
                    if(dis[i][0]%k==0) ans=min(ans,dis[i][0]/k);
                    else{
                    int valt=(dis[i][0]/k)+1;
                    if(valt%2) ans=min(ans,valt+1);
                    else{
                        ans=min(ans,valt);
                    }
                    }
                    
                    //奇数
                    if(dis[i][1]%k==0) ans=min(ans,dis[i][1]/k);
                    else{
                    int valt=(dis[i][1]/k)+1;
                    if(valt%2) ans=min(ans,valt);
                    else{
                        ans=min(ans,valt+1);
                    }

                    }
                cout<<ans*k<<" ";

                }else{
                    cout<<-1<<" ";
                }
            }
            else{//只能偶数的胜任
                if(dis[i][0]<1100000000){
                    int ans;
                    if(dis[i][0]%k){
                        ans=(dis[i][0]/k+1);
                    }
                    else{
                        ans=dis[i][0]/k;
                    }
                     cout<<ans*k<<" ";

                }else{
                    cout<<-1<<" ";
                }
            }
        }
        cout<<endl;
    }
}