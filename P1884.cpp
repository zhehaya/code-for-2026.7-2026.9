#include<bits/stdc++.h>
#define N 11451
#define INF 1145141919810
#define int long long
using namespace std;
int c[N][N];
int b[N];
int n;
pair<int,int> star[N][2];
map<int,int>li;//大到小
int lisan[N];//小到大
signed main()
{
    cin>>n;int numm=0;
    for(int i=1;i<=n;i++)
    {
        int x1,y1,x2,y2;
    cin>>x1>>y1;
    cin>>x2>>y2;
    star[i][0].first=min(x1,x2);
    star[i][0].second=min(y1,y2);
    star[i][1].first=max(x1,x2);
    star[i][1].second=max(y1,y2);
    b[numm+1]=star[i][0].first,b[numm+2]=star[i][0].second;
    b[numm+3]=star[i][1].first,b[numm+4]=star[i][1].second;
    numm+=4;
    }
    sort(b+1,b+1+numm);
    numm=0;b[0]=INF;
    for(int i=1;i<=4*n;i++)
        if(b[i]!=b[i-1]) {
            //cout<<b[i]<<" ";
            lisan[++numm]=b[i];li[b[i]]=numm;//cout<<"k"<<numm<<" ";
        }
        //cout<<numm<<endl;
    for(int i=1;i<=n;i++)
        {
            c[li[star[i][0].second]][li[star[i][0].first]]+=1;
            c[li[star[i][1].second]][li[star[i][1].first]]+=1;
            c[li[star[i][1].second]][li[star[i][0].first]]-=1;
            c[li[star[i][0].second]][li[star[i][1].first]]-=1;
        }
   //  for(int i=1;i<=numm;i++) cout<<lisan[i]<<" ";  
    for(int i=1;i<=numm;i++)
        for(int j=1;j<=numm;j++)
            c[i][j]+=c[i][j-1];
    for(int i=1;i<=numm;i++)
        for(int j=1;j<=numm;j++)
            c[i][j]+=c[i-1][j];
    
    lisan[0]=-INF;
    int ans=0;int lineans=0;
    for(int i=1;i<=numm;i++)
    {
        ans+=(lineans*(lisan[i]-lisan[i-1]));
       // cout<<lineans<<endl;
        lineans=0;
        for(int j=2;j<=numm;j++)
        {
            if(c[i][j-1]>=1){
                lineans+=(lisan[j]-lisan[j-1]);
               // cout<<lineans<<" ";
            }
        }

    }
    cout<<ans;
    
    
}