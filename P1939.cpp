#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll P=1e9+7;

struct matrix{
    ll val[4][4];
    matrix(){
        memset(val,0,sizeof(val));
        val[1][1]=1;val[1][3]=1;val[2][1]=1;val[3][2]=1;
    }
    void outt(){
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
            cout<<val[i][j]<<" ";cout<<endl;
    }cout<<endl;}
    
    matrix operator*(matrix othe)
    {
        matrix res;
        memset(res.val,0,sizeof(res.val));
        for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
                for(int p=1;p<=3;p++)
                    res.val[i][j]=(res.val[i][j]+(val[p][j]*othe.val[i][p])%P)%P;
       // res.outt();
        return res;
    }
    matrix fastpow(ll k)
    {
        matrix res,nowval; 
        for(int i=1;i<=3;i++)
        {
        for(int j=1;j<=3;j++)
                res.val[i][j]=0,nowval.val[i][j]=val[i][j];
        res.val[i][i]=1;
        }
            
        while(k>0)
        {
            if(k&1) res=res*nowval;
            nowval=nowval*nowval;
            k>>=1;
        }
        return res;
    }
    ll ans(){
        ll anss=val[1][1]+val[1][2]+val[1][3];
        return anss%P;
    }
};

int main()
{
    ll T,n;
    cin>>T;
    matrix pre;
    
    for(ll i =1;i<=T;i++)
     {
          cin>>n;
          if(n<=3) cout<<1<<endl;
          else cout<<pre.fastpow(n-3).ans()<<endl;
    }
}



