#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

struct DINIC{
    struct Edge{
        int to;
        ll cap;
        int rev;
    };
    vector<vector<Edge> > g;
    vector<int> lev, nx;
    void init(int _n) {
        g.assign(_n+5,vector<Edge>());
        lev.assign(_n+5,0);
        nx.assign(_n+5,0);
    }
    void add(int u, int v, ll c) {
        g[u].pb({v,c,int(g[v].size())});
        g[v].pb({u,c,int(g[u].size()-1)});
    }
    bool bfs(int s, int t) {
        fill(lev.begin(),lev.end(),0);
        queue<int> q;
        q.push(s);
        lev[s] = 1;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto [v,c,r] : g[cur]) {
                if (!lev[v] && c > 0) {
                    lev[v] = lev[cur]+1;
                    q.push(v);
                }
            }
        }
        return lev[t];
    }
    ll dfs(int u, int t, ll fw) {
        if (u == t) return fw;
        for (;nx[u] < g[u].size(); ++nx[u]) {
            auto& e = g[u][nx[u]];
            if (e.cap > 0 && lev[e.to] == lev[u]+1) {
                ll ans = dfs(e.to,t,min(fw,e.cap));
                if (ans > 0) {
                    e.cap -= ans;
                    g[e.to][e.rev].cap += ans;
                    return ans;
                }
            }
        }
        return 0;
    }
    ll flow(int s, int t) {
        ll ans = 0;
        while(bfs(s,t)) {
            fill(nx.begin(),nx.end(),0);
            ll f;
            while((f = dfs(s,t,1e18)) > 0) {
                ans += f;
            }
        }
        return ans;
    }
} din;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;    
    din.init(n);
    vector<vector<int> > g(n+1);
    while(m--) {
        int u, v;
        cin>>u>>v;
        din.add(u,v,1);
        g[u].pb(v);
        //din.add(v,u,1);
    }
    cout<<din.flow(1,n)<<endl;
    din.bfs(1,n);
    for (int i = 1; i <= n; ++i) {
        if (din.lev[i]) {
            for (auto v : g[i]) {
                if (!din.lev[v]) {
                    cout<<i<<' '<<v<<endl;
                }
            }
        }
    }
    
    return 0;
}
