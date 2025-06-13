#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

using ll = long long int;
#define vi vector<int>
#define vll vector<ll>
#define akitama return 0

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vll cnt(3, 0); // L T I
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'L') cnt[0]++;
        else if (s[i] == 'T') cnt[1]++;
        else cnt[2]++;
    }
    
    // Check if already balanced
    if (cnt[2] == cnt[0] && cnt[0] == cnt[1]) {
        cout << 0 << endl;
        return;
    }
    
    vll n_cnt(3, 0);
    n_cnt[0] = n - cnt[0];
    n_cnt[1] = n - cnt[1];
    n_cnt[2] = n - cnt[2];
    
    if (n_cnt[0] < 0 || n_cnt[1] < 0 || n_cnt[2] < 0) {
        cout << -1 << endl;
        return;
    }

    auto check = [&](char c) {
        if (c == 'L') return n_cnt[0] > 0;
        else if (c == 'T') return n_cnt[1] > 0;
        else return n_cnt[2] > 0;
    };
    
    auto _check = [&](char c1, char c2) {
        if ((c1 == 'L' && c2 == 'T') || (c1 == 'T' && c2 == 'L'))
            return 'I';
        else if ((c1 == 'L' && c2 == 'I') || (c1 == 'I' && c2 == 'L'))
            return 'T';
        return 'L';
    };
    
    ll op = 0, mop = n * 2;
    vll ans;
    
    while (op < mop) {
        bool f = false;
        for (int i = 0; i < (int)s.size() - 1; ++i) { 
            if (s[i] != s[i+1]) {
                char ch = _check(s[i], s[i+1]);
                if (check(ch)) {
                    s.insert(s.begin() + i + 1, ch);
                    ans.push_back(i+1);
                    if (ch == 'L') n_cnt[0]--;
                    else if (ch == 'T') n_cnt[1]--;
                    else n_cnt[2]--;
                    f = true;
                    op++;
                    break;
                }
            }
        }
        if (!f) break;
    }
    
    if (op != mop) {
        cout << -1 << endl;
    } else {
        cout << op << endl;
        for (auto &i : ans) cout << i << endl;
    }
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _; cin >> _;
    while (_--) { 
        solve();
    }
    akitama;
}