#include<bits/stdc++.h>
#define N 414514
using namespace std;
bool isprime[N]; // isprime[i]表示i是不是素数
int prime[N]; // 现在已经筛出的素数列表
int kn=214514; // 上限，即筛出<=n的素数
int cnt; // 已经筛出的素数个数
void euler()//欧拉筛模板
{
    memset(isprime, true, sizeof(isprime)); 
    isprime[1] = false;
    for(int i = 2; i <= kn; ++i) {
        if(isprime[i]) prime[++cnt] = i;
        for(int j = 1; j <= cnt && i*prime[j] <= kn; ++j)
        {
            isprime[i * prime[j]] = false;
            if(i % prime[j] == 0) break;
        }
    }
}
int T,n;
int main()
{
    euler();
scanf("%d",&T);
while(T--)
{
scanf("%d",&n);
if(!isprime[n-1]){
    for(int i=1;i<=n;i++) printf("%d ",i);
}
else{
    
  if(n<7)
    printf("-1");
  else{
    for(int i=1;i<=n-4;i++) printf("%d ",i);
    for(int i=n;i>=n-3;i--) printf("%d ",i);
  }  
}printf("\n");
}

}