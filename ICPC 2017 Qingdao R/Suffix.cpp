#include<bits/stdc++.h>
using namespace std;
int T,n;
string val[61451];
string minn(string a,string b)
{
    int alen=a.length(),blen=b.length();
    int cc=abs(alen-blen);
    if(alen>blen) {
        for(int i=1;i<=cc;i++) b.push_back('0');
    }
    else{
        for(int i=1;i<=cc;i++) a.push_back('0');
    }
    if(a>b){
        return b.substr(0,blen);
    }
    else{
        return a.substr(0,alen);
    }
}
int main()
{
    cin>>T; 
    for(int i=1;i<=T;i++)
    {
        cin>>n;
        for(int j=1;j<=n;j++)
            cin>>val[j];
        string answ="";
        string lst;
        int len=val[n].length();
        string ans=val[n];
        for(int t=0;t<=len-1;t++)
            {
                string x=val[n].substr(t,len);
                ans=minn(ans,x);
            }
        answ=ans+answ;
        lst=answ;
        for(int j=n-1;j>=1;j--)
        {
            int len=val[j].length();
            string ans=val[j]+lst;
            for(int t=0;t<=len-1;t++)
            {
                string x=val[j].substr(t,len-t+1)+lst;
                //cout<<endl<<x<<"--te"<<endl;
                ans=minn(ans,x);
            }
            int anslen=ans.length();
            answ=ans.substr(0,anslen-1)+answ;
            lst=answ;
        }
        cout<<answ<<endl;
    }
}
//TLE
