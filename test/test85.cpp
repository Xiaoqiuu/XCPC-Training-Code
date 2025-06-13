// 并查集
#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

#define akitama return 0;

constexpr int N = 1e5 + 7;
int fa[N];

inline void init(int n) {
    for (int i = 1; i <= n; ++ i) {
        fa[i] = i;
    }
}
int find(int i) {
    if (fa[i]==i){
        return i;
    } else return find(fa[i]);
}

inline void merge(int i, int j) {
    fa[find(i)] = find(j);
}

void solve() {
    init(5);
    merge(5, 4);
    merge(3, 2);
    merge(4, 2);
    merge(4, 1);
    cout << find(5) << endl;
}

signed main() {
    cin.tie(0)->ios::sync_with_stdio(false);
    solve();
    akitama;
}