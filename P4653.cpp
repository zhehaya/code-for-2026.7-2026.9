#include<bits/stdc++.h>
#define N 214514
using namespace std;
double a[N],b[N];
int n;
bool cmp(double fi,double se)
{
    return fi>se;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i]; 
    sort(a+1,a+1+n,cmp);
    sort(b+1,b+1+n,cmp);
    int bflag=0;
    double ans=0,bsum=0,asum=0,answ;
    for(int i=1;i<=n;i++)//选a
    {
        asum+=a[i];
        while(bsum<asum&&bflag<=n)
        {
            bflag++;
            bsum+=b[bflag];            
        }
        if(bflag<=n) {
            answ=asum-double(bflag+i);//war
            //cout<<answ<<endl;
            ans=max(answ,ans);
        }
    }
    bflag=0;
    int aflag=0;
    bsum=0,asum=0;
    for(int i=1;i<=n;i++)//选b
    {
        bsum+=b[i];
        while(asum<bsum&&aflag<=n)
        {
            aflag++;
            asum+=a[aflag];            
        }
        if(aflag<=n) {
            answ=bsum-double(aflag+i);//war
            ans=max(answ,ans);
        }

    }
    cout<<fixed<<setprecision(4)<<ans;

}