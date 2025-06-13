#include <iostream>
using namespace std;

#define akitama return 0
#define ll long long int
#define vi vector<int>

constexpr int N = 1e5 + 7;
int fa[N];

inline void init(int n) {
    for (int i = 1; i <= n; ++ i) {
        fa[i] = i;
    }
}

int find(int x) {
    if (fa[x] == x) {
        return x;
    } else {
        return find(fa[x]);
    }
}

inline void merge(int i, int j){
    fa[find(i)] = find(j);
}

void solve() {
    int n, m, p;
    cin >> n >> m >> p;
    init(n);
    while (m--) {
        int x, y;
        cin >> x >> y;
        merge(x, y);
    }
    while (p--) {
        int x, y;
        cin >> x >> y;
        if (find(x)==find(y)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1;
    while (_--) {
        solve();
    }
    akitama;
}