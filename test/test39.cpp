// 欧拉序列

#include <iostream>
#include <unordered_map>
using namespace std;
#define mem(a, b) memset(a, b, sizeof(a))
#define akitama return 0

const int N = 1e6 + 7;
// int _dfs[200020], len;
int n, m, rt;
int tot, head[N];
struct edge {
    int to, next;
} e[N << 1];

inline void add(int u, int v) {
    e[++tot] = (edge){v, head[u]};
    head[u] = tot;
}

int dep[N], lg[N<<1], fa[N<<1][21];





void dfs(int u, int fa) {
    dfs_[++len] = u;

}

void solve() {
    int root;
    cin >> n >> m >> root;

}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    //int _; cin >> _;
    //while (_--)
    solve();
    akitama;
}