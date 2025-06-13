#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m, L;
    cin >> n >> m >> L;
    
    vector<pair<int, int>> hrd(n);
    vector<pair<int, int>> pow(m);
    
    for (int i = 0; i < n; ++i) cin >> hrd[i].first >> hrd[i].second;
    for (int i = 0; i < m; ++i) cin >> pow[i].first >> pow[i].second;
    
    int pos = 1, jp = 1, cnt = 0;
    int hi = 0, pi = 0;
    
    while (pos < L) {
        // 1. 检查当前位置能跳跃的最远位置
        while (pi < m && pow[pi].first <= pos + jp) {
            pi++;
        }
        
        // 2. 判断是否遇到障碍
        bool can_jump = false;
        while (hi < n && hrd[hi].first <= pos + jp) {
            if (hrd[hi].second > pos + jp) {
                can_jump = true;
                break;
            }
            hi++;
        }
        
        // 3. 如果当前跳跃力足够，可以跳到下一个位置
        if (!can_jump) {
            pos += jp;
        } else {
            // 4. 如果无法跳跃，需要收集道具来提升跳跃力
            if (pi == 0) {
                cout << -1 << endl;
                return;
            }
            
            jp += pow[pi - 1].second;
            cnt++;
        }
        
        if (pos >= L) break;
    }
    
    if (pos >= L) {
        cout << cnt << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
