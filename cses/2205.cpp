#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int n;

void dfs(int s, vector<int> &v) {
    v[s] = 1;
    for (int i = 0; i < n; ++i) cout<<((s>>i)&1);
    cout<<endl;
    for (int i = 0; i < n; ++i) {
        if (!v[s^(1<<i)]) dfs(s^(1<<i),v);
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n;
    vector<int> v((1<<n)+5,0);
    dfs(0,v);
    return 0;
}
