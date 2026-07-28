#include<bits/stdc++.h>
using namespace std;
int T,n;
struct ss{
    int id;
    string v;
    bool operator < (const ss & b) const{
        return v>b.v;
    }
};
priority_queue<ss>suf;
int main()
{
    cin>>T; 
    for(int i=1;i<=T;i++)
    {
        cin>>n;
        int flag=0;
        for(int j=1;j<=n;j++)
        {
            string val;
            cin>>val;
            reverse(val.begin(),val.end());
            suf.push({j,val});
        }
        int la=0,t=10;
        while(true&&!suf.empty())
        {
            if(suf.top().id!=la) flag++;
            la=suf.top().id;
            ss nex={suf.top().id,suf.top().v};
            cout<<suf.top().v[0];
            suf.pop();
            nex.v.erase(nex.v.begin());//cout<<"--"<<nex.v<<"--";
            if(nex.v.length()==0) continue;
            
            suf.push(nex);
        }
        cout<<endl;
    }
}
