#include<bits/stdc++.h>
#define N 2145141
int n,k;
int a[N];
using namespace std;
deque<pair<int,int>>qe;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        while(!qe.empty()&&qe.back().first<a[i]) qe.pop_back();
        if(i>=k){
            while(qe.front().second<i-k+1)qe.pop_front();
            cout<<qe.front().first<<endl;
        }
        qe.push_back({a[i],i});
    }
}