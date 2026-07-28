#include<bits/stdc++.h>
#define N 114514
#define int long long
using namespace std;
namespace SEG{//线段树板子
    int tree_[N<<2],lazy_[N<<2];
    void pushup(int rt){ tree_[rt]=tree_[rt<<1]+tree_[rt<<1|1]; }
    void pushdown(int rt,int l,int r){
        if(lazy_[rt]){
            int mid=(l+r)>>1;
            tree_[rt<<1]+=lazy_[rt]*(mid-l+1);
            tree_[rt<<1|1]+=lazy_[rt]*(r-mid);
            lazy_[rt<<1]+=lazy_[rt];
            lazy_[rt<<1|1]+=lazy_[rt];
            lazy_[rt]=0;
        }
    }
    void build(int rt,int l,int r,int *a){
        if(l==r){ tree_[rt]=a[l]; return; }
        int mid=(l+r)>>1;
        build(rt<<1,l,mid,a);
        build(rt<<1|1,mid+1,r,a);
        pushup(rt);
    }
    void update(int rt,int l,int r,int ql,int qr,int val){
        if(ql<=l&&r<=qr){
            tree_[rt]+=val*(r-l+1);
            lazy_[rt]+=val;
            return;
        }
        pushdown(rt,l,r);
        int mid=(l+r)>>1;
        if(ql<=mid) update(rt<<1,l,mid,ql,qr,val);
        if(qr>mid) update(rt<<1|1,mid+1,r,ql,qr,val);
        pushup(rt);
    }
    int query(int rt,int l,int r,int ql,int qr){
        if(ql<=l&&r<=qr) return tree_[rt];
        pushdown(rt,l,r);
        int mid=(l+r)>>1;
        int res=0;
        if(ql<=mid) res+=query(rt<<1,l,mid,ql,qr);
        if(qr>mid) res+=query(rt<<1|1,mid+1,r,ql,qr);
        return res;
    }
}
namespace HLD{
    //树的常规信息---
    vector<int>tree[N];
    int fa[N],size[N],depth[N];//深度用于lca
    //---树的常规信息


    int top[N];//链头
    int wson[N];//重儿子
    int hld_dfn[N],dfncnt;//dfn序（一条重链和一个子树dfn序连续
    int hld_id[N];//dfn序对应的原节点编号
    void dfs1(int u,int father){//第一次dfs找到重儿子，父亲,子树重量和深度
        size[u]=1;fa[u]=father;
        depth[u]=depth[father]+1;
        for(int v:tree[u])
        {
            if(v!=father){//不回父边
                dfs1(v,u);
                size[u]+=size[v];
                if(size[v]>size[wson[u]]) wson[u]=v;//重儿子更换
            }
            
        }
    }
    void dfs2(int u,int father,int utop){//第二次dfs创建重链，标记链头，找到dfn序
        top[u]=utop;
        hld_dfn[u]=(++dfncnt);//dfs序
        hld_id[dfncnt]=u;
        //.........//可添加dfs序维护的东西
        if(wson[u]!=0) dfs2(wson[u],u,utop);//先遍历重儿子，链头不变
        for(int v:tree[u]){
            if(v!=father&&v!=wson[u]){
                dfs2(v,u,v);//再遍历轻儿子，链头变为轻儿子自身
            }
        }
    }
    int lca(int u,int v){//使用HLD找到LCA//也可改为返回ans
        while(top[u]!=top[v])
        {
            if(depth[top[u]]>depth[top[v]]) swap(u,v);//保证v的链头深度较深
            //...//这里可以更新dfs序中的[hld_dfn[top[v]],hld_dfn[v]]
            v=fa[top[v]];
        }
        if(depth[u]>depth[v]) swap(u,v);// 保证v比较深
        //...//这里可以更新[hld_dfn[u],hld_dfn[v]]
        return u;
        
    }

    // 单点修改：节点x权值增加a
    void updatePoint(int x,int a){
        SEG::update(1,1,dfncnt,hld_dfn[x],hld_dfn[x],a);
    }
    // 子树修改：以x为根的子树所有点权值增加a
    void updateSubtree(int x,int a){
        SEG::update(1,1,dfncnt,hld_dfn[x],hld_dfn[x]+size[x]-1,a);
    }
    // 查询x到根路径上所有点权和
    int queryToRoot(int x){
        int res=0;
        while(x!=0){
            res+=SEG::query(1,1,dfncnt,hld_dfn[top[x]],hld_dfn[x]);
            x=fa[top[x]];
        }
        return res;
    }
}
int n,m;
int a[N];
signed main()
{
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%lld%lld",&u,&v);
        HLD::tree[u].push_back(v);
        HLD::tree[v].push_back(u);
    }
    HLD::depth[0]=0;
    HLD::dfs1(1,0);
    HLD::dfs2(1,0,1);

    // 按dfn序重排点权，建线段树
    static int b[N];
    for(int i=1;i<=n;i++){
        b[HLD::hld_dfn[i]]=a[i];
    }
    SEG::build(1,1,HLD::dfncnt,b);

    for(int i=0;i<m;i++){
        int op,x,val;
        scanf("%lld%lld",&op,&x);
        //cout<<op<<endl;
        if(op==1){
            scanf("%lld",&val);
            HLD::updatePoint(x,val);
            
        }else if(op==2){
            scanf("%lld",&val);
            HLD::updateSubtree(x,val);
        }else{
            printf("%lld\n",HLD::queryToRoot(x));
        }
    }
}