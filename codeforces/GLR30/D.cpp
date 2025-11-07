#include <bits/stdc++.h>
using namespace std;
#define akitama return 0
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n, km; cin >> n >> km;
        string s, t; cin >> s >> t;
        if (s[0] != t[0]) { cout << -1 << '\n'; continue; }
        vector<int> pos[26];
        for (int i = 0; i < n; ++ i) pos[s[i]-'a'].push_back(i);
        auto ok = [&](int K, vector<int>* pp = nullptr) -> bool {
            int lst = 0;
            if (pp) { pp->assign(n, -1); (*pp)[0] = 0; }
            for (int i = 0; i < n; ++ i) {
                auto &v = pos[t[i]-'a'];
                if (v.empty()) return false;
                int L = max(lst, i - K), R = i;
                auto it = lower_bound(v.begin(), v.end(), L);
                if (it == v.end() || *it > R) return false;
                lst = *it;
                if (pp) (*pp)[i] = lst;
            }
            return true;
        };
        int lo = 0, hi = km, k = -1;
        while (lo <= hi) {
            int md = (lo + hi) / 2;
            if (ok(md)) { k = md; hi = md - 1; }
            else lo = md + 1;
        }
        if (k == -1) { cout << -1 << '\n'; continue; }
        vector<int> p, d(n);
        ok(k, &p);
        for (int i = 0; i < n; ++ i) d[i] = i - p[i];
        cout << k << '\n';
        string cur = s, nxt(n, 'a');
        for (int st = 1; st <= k; ++ st) {
            nxt[0] = cur[0];
            for (int i = 1; i < n; ++ i) nxt[i] = (d[i] >= st? cur[i-1] : cur[i]);
            cout << nxt << '\n';
            cur.swap(nxt);
        }
    }
    akitama;
}
