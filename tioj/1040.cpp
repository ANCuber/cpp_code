#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long,long long> 
#define p_q priority_queue
#define endl '\n'

int flag = 0;

void solve (int p, int q){
    int pnt = flag;
    if (p%q == 0) {
        cout<<p/q;
    } else {
        if (pnt) cout<<'{';
        cout<<p/q<<"+1/";
        flag = 1;
        solve(q,p%q);
        if (pnt) cout<<'}';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;    
    while(t--) {
        flag = 0;
        ll p, q; cin>>p>>q;
        cout<<p<<'/'<<q<<" = ";
        solve(p,q);
        cout<<endl;
    }
    return 0;
}
