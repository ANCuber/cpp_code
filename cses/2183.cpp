#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define int ll

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    vector<int> c(n);
    for (auto& i : c) cin>>i;
    sort(c.begin(),c.end()); 
    int s = 0;
    for (auto i : c) {
        if (i <= s+1) {
            s += i;
        } else {
            break;
        }
    }
    cout<<s+1<<endl;
    return 0;
}
