#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

const int N = 1e5 + 7;
ll a[N], cnt[N][20];
vector<int> g[N];
//int vis[N];
ll ans = 0;
void dfs(int u, int fa) {
    cnt[u][a[u]] ++;
    for(auto v : g[u]) {
        if(v == fa) continue;
        dfs(v, u);
        for(int i = 0; i < 10; ++ i) {
            for(int j = 0; j < 10; ++ j) {
                if (i + j < 10)
                ans += cnt[u][i] * cnt[u][j];
            }
        }
        for (int i = 0; i < 10; ++ i) {
            cnt[u][a[u] + i] += cnt[v][i];
        }
    }
}

void solve() {
    int t;cin >> t;
    for(int i = 1; i <= t; ++ i) {
        cin >> a[i];
    }
    for(int i = 1; i < t; ++ i) {
        int u, v;cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);  
    }
    dfs(1, 0);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}