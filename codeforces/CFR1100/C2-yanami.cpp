#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned int;

using i128 = __int128;
using u128 = unsigned __int128;

void solve() {
    int n;
    std::cin >> n;

    std::vector<i64> a(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<i64> s1(n + 1, 0), s2(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        s1[i + 1] = s1[i] + a[i];
        s2[i + 1] = s2[i] + std::abs(a[i]);
    }

    int m = n;
    i64 s = s1[n];
    for (int i = 0; i < n; ++i) {
        if (a[i] > 0 && s2[i] - a[i] + s1[n] - s1[i + 1] > s) {
            m = i;
            s = s2[i] - a[i] + s1[n] - s1[i + 1];
        }
    }
    std::vector<int> ans;
    if (m < n) {
        int sign = 1;
        for (int i = m - 1; i >= 0; --i) {
            if (sign * a[i] > 0) {
                ans.push_back(i);
                sign = -sign;
            }
        }
        ans.push_back(m);
    }
    std::cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i) {
        std::cout << (ans[i] + 1) << " \n"[i + 1 == ans.size()];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}