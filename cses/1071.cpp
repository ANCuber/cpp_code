#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;    
    while(t--) {
        ll x, y; cin>>x>>y;
        if (x > y) {
            if (x&1) {
                cout<<(x-1)*(x-1)+y<<endl;
            } else {
                cout<<x*x-y+1<<endl;
            }
        } else if (x < y) {
            if (y&1) {
                cout<<y*y-x+1<<endl;
            } else {
                cout<<(y-1)*(y-1)+x<<endl;
            }
        } else {
            cout<<x*x-y+1<<endl;
        }
    }
    
    return 0;
}
