#include <iostream>
#include <vector>
#include <set>
using namespace std;
using ll = long long;

#define akitama return 0
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back

void solve() {
    int n, q;
    cin >> n >> q;
    vi x(q);
    for (int i = 0; i < q; ++i) {
        cin >> x[i];
    }

    set<pii> min_box;
    vector<int> bc(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        min_box.insert({0, i});
    }

    vi res;
    res.reserve(q);
    for (int cmd : x) {
        if (cmd >= 1) {
            min_box.erase({bc[cmd], cmd});
            bc[cmd]++;
            min_box.insert({bc[cmd], cmd});
            res.pb(cmd);
        } else {
            auto it = min_box.begin();
            int id = it->second;
            min_box.erase(it);
            bc[id]++;
            min_box.insert({bc[id], id});
            res.pb(id);
        }
    }

    for (int i = 0; i < q; ++i) {
        if (i) cout << ' ';
        cout << res[i];
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    akitama;
}