#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

const ll mod = 1e9+7;
const ll inv = (mod+1)/2;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n; cin>>n;
    ll cur = 1, ans = 0;
    while(cur <= n) {
        ans = (ans + (n/cur) * ((n/(n/cur))-cur+1)%mod * ((n/(n/cur)+cur)%mod)%mod * inv%mod)%mod;
        cur = n/(n/cur)+1;
    }
    cout<<ans<<endl;
    return 0;
}
