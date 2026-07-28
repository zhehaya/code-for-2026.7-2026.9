#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Linear{
    int b[31];
    Linear() {
        memset(b, 0, sizeof(b));
    }
    void insert(int x) {
        for (int i=30; i>= 0;i--) {
            if (((x>>i)&1)==0) continue;
            if(!b[i]){
                b[i]=x;
                return;
            }
            x^=b[i];
        }
    }
    int queryMax() {
        int res=0;
        for (int i=30;i>=0;i--)  res=max(res,res^b[i]);
        return res;
    }
};
signed main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin>>n;
        vector<int>a(n);
        int total=0;
        for (int i=0; i<n;i++) {
            cin>>a[i];
            total^=a[i];
        }
        Linear lb;
        int mask=((1LL<<31)-1)^total;
        for (int x:a) {
            lb.insert(x&mask);
        }
        int best=lb.queryMax();
        cout<<total+2*best<<endl;
    }
}