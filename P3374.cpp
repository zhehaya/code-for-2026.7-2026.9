#include<bits/stdc++.h>
#define N 1145141
using namespace std;
namespace BIT{
   int bit[N];//树状数组本体
   int n;//树状数组大小
   int lowbit(int x) {return x&(-x);}
   void update(int id,int date)//单点加
   {
        for(int i=id;i<=n;i+=lowbit(i)) bit[i]+=date;
   }
   int query(int id)//查询前缀和
   {
        int res=0;
        for(int i=id;i>0;i-=lowbit(i)) res+=bit[i];
        return res;
   }
}
int m;
int main()
{
cin>>BIT::n>>m;
for(int i=1;i<=BIT::n;i++) {
    int x;
    cin>>x;
    BIT::update(i,x);
}

while(m--)
{
    int opt,x,y;
    cin>>opt>>x>>y;
    if(opt==1) BIT::update(x,y);
    else cout<<BIT::query(y)-BIT::query(x-1)<<endl;
}
}