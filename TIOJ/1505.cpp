#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define p_q priority_queue

string ans[2] = {"zzz...","Asssss!!"};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    int n;
    while(t--) {
        cin>>n;
        vector<ll> a(n);
        for (auto& i : a) cin>>i;
        ll mod = a[1];
        ll cur = 1;
        for (int i = 0; i < n; ++i) {
            if (i == 1) continue;
            cur *= a[i];
            cur %= mod;
        }
        cout<<ans[(cur%mod==0)]<<endl;
    }
    return 0;
}
