#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

#define ll long long
#define ul unsigned long long
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define akitama return 0
#define pb push_back
#define mp make_pair
#define fi first
#define se second

const int MOD = 998244353;
const int N = 100005;

int anc(const vector<vi>& up, int a, int k, int lg) {
    for (int i = 0; i < lg; i++) {
        if (k & (1 << i)) a = up[a][i];
    }
    return a;
}

int findLCA(const vector<vi>& up, const vi& dis, int a, int b, int lg) {
    if (dis[a] < dis[b]) swap(a, b);
    int d = dis[a] - dis[b];
    a = anc(up, a, d, lg);
    if (a == b) return a;
    for (int i = lg - 1; i >= 0; i--) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

int g_next(const vector<vi>& up, const vi& dis, int a, int b, int lg) {
    if (a == b) return a;
    int w = findLCA(up, dis, a, b, lg);
    if (w == a) {
        int d = dis[b] - dis[a];
        return anc(up, b, d - 1, lg);
    } else {
        return up[a][0];
    }
}

void solve() {
    int n, st, en;
    cin >> n >> st >> en;
    vector<vi> gra(n + 1);
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        gra[u].pb(v);
        gra[v].pb(u);
    }

    vi dis(n + 1, -1), par(n + 1, 0);
    queue<int> que;
    dis[en] = 0;
    par[en] = en;
    que.push(en);

    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        for (auto nx : gra[cur]) {
            if (dis[nx] == -1) {
                dis[nx] = dis[cur] + 1;
                par[nx] = cur;
                que.push(nx);
            }
        }
    }

    int lg = 0;
    while ((1 << lg) <= n) lg++;
    vector<vi> up(n + 1, vi(lg, 0));
    for (int i = 1; i <= n; i++) up[i][0] = par[i];
    for (int j = 1; j < lg; j++) {
        for (int i = 1; i <= n; i++) {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }

    vi arr(n);
    for (int i = 0; i < n; i++) arr[i] = i + 1;
    sort(arr.begin(), arr.end(), [&](int a, int b) {
        if (dis[a] == dis[b]) return a < b;
        return dis[a] > dis[b];
    });

    int cur = st;
    for (auto x : arr) {
        if (cur == x) continue;
        cur = g_next(up, dis, cur, x, lg);
    }

    if (cur == en) {
        for (auto x : arr) cout << x << " ";
        cout << "\n";
    } else {
        cout << -1 << "\n";
    }
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _;
    cin >> _;
    while (_) {
        solve();
        _--;
    }
    akitama;
}