#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 1e5 + 7;

int head[MAXN];
int cnt = 0;

struct node {
    int to;
    int w;
    int nxt;
} edge[MAXN];

void init() {
    memset(head, -1, sizeof(head));
    cnt = 0;
}

void add(int u, int v, int w) {
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].nxt = head[u];
    head[u] = cnt++;
}

bool check(int u, int v) {
    for (int i = head[u]; ~i;i = edge[i].nxt) {
        if (edge[i].to == v) return true;
    }
    return false;
}

// void dfs(int u) {
//     if ()
// }

int main() {
    int n, q; cin >> n >> q;
    init();
    for (int i = 0; i < n; ++ i) {
        int u, v, w; cin >> u >> v >> w;
        add(u, v, w);
    }
    for (int i = 1; i <= q; ++ i) {
        int u, v; cin >> u >> v;
        cout << (check(u, v) ? "Yes" : "No") << std::endl;
    }
    return 0;
}