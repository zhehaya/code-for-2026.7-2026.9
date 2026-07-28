#include<bits/stdc++.h>
#define N 1145
using namespace std;
char mar[N][N];
int n,m;
int upp[N][N],le[N][N],ri[N][N];
int ans=0;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>mar[i][j];
    for(int i=0;i<=1111;i++)
        ri[0][i]=1145141,le[0][i]=1145141;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            {
                if(mar[i][j]=='F') 
                {
                    upp[i][j]=upp[i-1][j]+1;//悬线长度
                    if(mar[i][j-1]=='F') le[i][j]=le[i][j-1]+1;
                    else le[i][j]=1;
                }
                else le[i][j]=1145141,upp[i][j]=0;
            //cout<<le[i][j]<<" ";
            }
            //cout<<endl;
        for(int j=m;j>=1;j--)
        {
            if(mar[i][j]=='F') {
                if(mar[i][j+1]=='F')ri[i][j]=ri[i][j+1]+1;
                else ri[i][j]=1;
                //cout<<ans<<endl;
            }
            else ri[i][j]=1145141;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            if(mar[i][j]=='F') 
                le[i][j]=min(le[i][j],le[i-1][j]);
            //cout<<le[i][j]<<" ";
            //cout<<endl;
        for(int j=m;j>=1;j--)
            if(mar[i][j]=='F') 
            {               
                ri[i][j]=min(ri[i][j],ri[i-1][j]);
                ans=max(ans,upp[i][j]*(ri[i][j]+le[i][j]-1));
            }          
                //cout<<ans<<endl;
    }
    cout<<3*ans;
    return 0;
        
    
}