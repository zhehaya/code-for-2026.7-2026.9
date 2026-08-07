#include<bits/stdc++.h>
#define N 1145141
using namespace std;
namespace segment{
    int a[N];//
    struct Node{
        int lazyl,lazyr,lazyd;//lazy标记，对应从哪个端点开始，到哪个端点结束和乘了多少
        bool lazy=false;
        int val;//如果叶子节点则有值
    }seg[4*N];
    void push_down(int,int,int);
    void update_single(int id,int l,int r,int D,int L,int R){
        if(L==R) {seg[id].val+=(D*a[L]);return;}
        push_down(id,l,r);
        seg[id].lazyd=D;
        seg[id].lazyl=L;
        seg[id].lazyr=R;
        seg[id].lazy=true;
        
    }
    void push_down(int id,int l,int r)
    {
        if(seg[id].lazy){
            int mid=(l+r)>>1;
            int lazymid=mid-l+seg[id].lazyl;
            update_single(id<<1,l,mid,seg[id].lazyd,seg[id].lazyl,lazymid);
            update_single((id<<1)+1,mid+1,r,seg[id].lazyd,lazymid+1,seg[id].lazyr);
            seg[id].lazy=false;
        }
    }
    void update(int id,int l,int r,int D,int L,int R){
        if(L<=l&&r<=R){
            update_single(id,l,r,D,l-L,r-L);
            return;
        }push_down(id,l,r);
        int mid=(l+r)>>1;
        if(L<=mid){
            update(id<<1,l,mid,D,L,R);
        }if(R>mid){
            update((id<<1)+1,mid+1,r,D,L,R);
        }
    }
    int query(int id,int l,int r,int queryid){
        if(l==r) return seg[id].val;
        push_down(id,l,r);
        int mid=(l+r)>>1;
        if(queryid<=mid){
            return query(id<<1,l,mid,queryid);
        }
        else{
            return query((id<<1)+1,mid+1,r,queryid);
        }
    }
}

int n,m;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
        x=x*10+ch-'0',ch=getchar();
    return x*f;
}
void write(int x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
    
    return;
}
int main()
{
n=read(),m=read();
for(int i=0;i<=n;i++) segment::a[i]=read();
for(int i=0;i<=m;i++)
{
    int x=read();
    segment::update(1,0,n+m+1,x,i,n+i);
}
for(int i=0;i<=n+m;i++)
{
    write(segment::query(1,0,n+m+1,i));putchar(' ');
}
}