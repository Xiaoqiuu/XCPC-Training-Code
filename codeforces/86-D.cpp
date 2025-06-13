#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, t;
    cin >> n >> t;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }
    
    vector<array<int, 3>> query(t + 1);
    for (int i = 1; i <= t; ++i) {
        int l, r;
        cin >> l >> r;
        query[i] = {l, r, i};
    }
    
    int block_size = n / min<int>(n, sqrt(t));
    vector<int> K(n + 1);
    for (int i = 1; i <= n; ++i) {
        K[i] = (i - 1) / block_size + 1;
    }
    
    sort(query.begin() + 1, query.end(), [&](auto x, auto y) {
        if (K[x[0]] != K[y[0]]) {
            return x[0] < y[0];
        }
        return (K[x[0]] & 1) ? (x[1] < y[1]) : (x[1] > y[1]);
    });
    
    int l = 1, r = 0;
    long long val = 0;
    vector<int> cnt(1000007, 0);
    vector<long long> ans(t + 1);
    
    auto add = [&](int x) {
        val -= 1LL * cnt[x] * cnt[x] * x;
        cnt[x]++;
        val += 1LL * cnt[x] * cnt[x] * x;
    };
    
    auto del = [&](int x) {
        val -= 1LL * cnt[x] * cnt[x] * x;
        cnt[x]--;
        val += 1LL * cnt[x] * cnt[x] * x;
    };
    
    for (int i = 1; i <= t; ++i) {
        auto [ql, qr, id] = query[i];
        while (l > ql) add(w[--l]);
        while (r < qr) add(w[++r]);
        while (l < ql) del(w[l++]);
        while (r > qr) del(w[r--]);
        ans[id] = val;
    }
    
    for (int i = 1; i <= t; ++i) {
        cout << ans[i] << '\n';
    }
    
    return 0;
}