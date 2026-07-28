#include<bits/stdc++.h>
using namespace std;
int T,n;
int outt[50][50];
int tolist[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
void pre(int n)
{
    for(int i=1;i<=40;i++)
        for(int j=1;j<=40;j++)
            outt[i][j]=0;
    for(int i=0;i<=40;i++) outt[n+3][i]=1,outt[i][n+3]=1;
}
bool calcp(int x,int y,int prex,int prey)
{
    outt[prex][prey]=0;
    if(outt[x+1][y]||outt[x-1][y]||outt[x][y+1]||outt[x][y-1]){
        outt[prex][prey]=1;
        return 1;
    } 
    outt[prex][prey]=1;
    return 0;
}
int main()
{
    for(int i=0;i<=40;i++) outt[i][0]=1,outt[0][i]=1;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cin>>n;
        pre(n);
        int nstate=0,a=2,b=2;
        while(true)
        {
            outt[a][b]=1;
            if(calcp(a+tolist[nstate][0],b+tolist[nstate][1],a,b)){
                nstate=(nstate+1)%4;
                if(calcp(a+tolist[nstate][0],b+tolist[nstate][1],a,b)) break;
            }
            a+=tolist[nstate][0];
            b+=tolist[nstate][1];
        }
        for(int i=2;i<=n+1;i++)
        {
            for(int j=2;j<=n+1;j++)
            {
                if(outt[i][j]) cout<<'#';
                else cout<<' ';
            }
            cout<<endl;
        }
            
    }
}