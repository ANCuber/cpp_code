#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

struct BIT{
    vector<int> a;
    int sz;
    void init(int _n) {
        sz = 1<<(__lg(_n)+1);
        a.assign(sz+2,0);
    }
    void add(int p, int v) {
        while(p <= sz) {
            a[p] += v;
            p += p&-p;
        }
    }
    int query(int g) {
        int p = 0, sum = 0;
        for (int i = __lg(sz); i >= 0; --i) {
            if (p+(1<<i) <= sz && sum+a[p+(1<<i)] < g) {
                sum += a[p+(1<<i)];
                p += (1<<i);
            }
        }
        return p+1;
    }
} bit;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k; cin>>n>>k;
    vector<int> a(n+1);
    set<int> s;
    map<int,int> mp, rmp;
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
        s.insert(a[i]);
    }
    int c = 0;
    for (auto i : s) mp[i] = ++c;
    for (int i = 1; i <= n; ++i) {
        rmp[mp[a[i]]] = a[i];
        a[i] = mp[a[i]];
    }
    bit.init(c);
    
    for (int i = 1; i <= k; ++i) {
        bit.add(a[i],1);
    }
    cout<<rmp[bit.query((k+1)/2)];
    for (int i = k+1; i <= n; ++i) {
        bit.add(a[i],1);
        bit.add(a[i-k],-1);
        cout<<' '<<rmp[bit.query((k+1)/2)];
    }
    cout<<endl;
    return 0;
}
