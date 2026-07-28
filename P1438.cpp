#include<bits/stdc++.h>
#define int long long
#define N 114514
using namespace std;
struct Node{
    //int id;
    //int val;
    int l,r;
    int lazyk=0,lazyd=0;
};
int m;
struct segment{
    int n;
    int a[N];
    Node tree[4*N];
    void maketag(int id,int k,int d)
    {
       
        tree[id].lazyk+=k;
        tree[id].lazyd+=d;
        return;
    }
    void pushtag(int id,int l,int r)
    { //cout<<id<<" "<<l<<" "<<r<<endl;
        if(l==r) return;
        int mid=(l+r)>>1;
        int rk=tree[id].lazyk+tree[id].lazyd*(mid-l+1);
        maketag(id<<1,tree[id].lazyk,tree[id].lazyd);
        maketag((id<<1)+1,rk,tree[id].lazyd);
        tree[id].lazyk=0;tree[id].lazyd=0;
        return;
    }
    /*
    void build(int id,int l,int r)
    {
        tree[id].l=l;tree[id].r=r;
        if(l==r){
            //tree[id].val=a[l];
            return;
        } 
        int mid=(l+r)>>1;
        build(id<<1,l,mid);
        build((id<<1)+1,mid+1,r);
        return;
    }*/
    void tagforlist(int id,int L,int R,int l,int r,int k,int d)
    {
        pushtag(id,l,r);
        if(l>=L&&r<=R){
            maketag(id,k+d*(l-L),d);
            return;
        }
        int mid=(l+r)>>1;
        //int rk=k+d*(mid-L+1);
        if(mid>=L)
            tagforlist(id<<1,L,R,l,mid,k,d);
       // else rk=k;
        if(mid<R)
            tagforlist((id<<1)+1,L,R,mid+1,r,k,d);
            
        return;
    }
    int querysingle(int id,int qid,int l,int r)
    {
        pushtag(id,l,r);
        if(l==r) {
            //cout<<id<<endl;
            //cout<<tree[id].lazyk<<endl;
            return a[qid]+tree[id].lazyk;}
        int mid=(l+r)>>1;
        if(qid<=mid) return querysingle(id<<1,qid,l,mid);
        else return querysingle((id<<1)+1,qid,mid+1,r);
    }
}SEG;
signed main()
{
cin>>SEG.n>>m;
for(int i=1;i<=SEG.n;i++) cin>>SEG.a[i];
while(m--)
{
    int opt;
    cin>>opt;
    if(opt==1){
        int l,r,k,d;
        cin>>l>>r>>k>>d;
        SEG.tagforlist(1,l,r,1,SEG.n,k,d);

    }else{
        int p;
        cin>>p;
        cout<<SEG.querysingle(1,p,1,SEG.n)<<endl;
    }
}
}