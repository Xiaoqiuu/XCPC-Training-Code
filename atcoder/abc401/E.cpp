#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define akitama return 0
#define vll vector<ll>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second

const int MOD = 1e9;

int main(){
    int n, m; cin >> n >> m;
    vector<vi> adj(n+1);vi ans(n+1, -1);
    vector<bool> vis(n+1, false);
    for (int i = 0; i < m; ++ i) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    queue<int> q;
    q.push(1);
    vis[1] = 1;
    int op = 0;

    for (int j = 1; j <= n; ++ j) {
        if(!vis[j]){
            cout << -1 << endl;
            continue;
        }
        vi tmp;
        for (auto u : adj[j]) {
            if (u > j && !(vis[u])) {
                tmp.pb(u);
            }
        }
        if (tmp.empty()) { ans[j] = op; }
        else {
            op += tmp.size();
            for (auto u : tmp) {
                if (!vis[u]) {
                    vis[u] = 1;
                    q.push(u);
                }
            }

            ans[j] = op;
        }
    }

    for (int k = 1; k <= n; ++ k) {
        cout << ans[k] << endl;
    }

    akitama;
}
