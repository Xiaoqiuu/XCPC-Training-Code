/*
 * @Author: Xiaoqiuu xiaoqiuuu@gmail.com
 * @Date: 2025-07-20 19:35:40
 * @LastEditors: Xiaoqiuu xiaoqiuuu@gmail.com
 * @LastEditTime: 2025-07-20 19:35:43
 * @FilePath: /workspace/nowcoder/113313/D1.cxx
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pb push_back
signed main() {
    int n, m; cin >> n >> m;
    // 6 5 4 3 2 1
    // 11 23
    // 45 66
    // 
    // i i
    // i i + 1
    // m ^ 2
    if ((m & 1) == 0) {
        cout << -1 << endl;
        return 0;
    }
    int num = 63 - __builtin_clzll(m);
    long long int pm = 1LL << num;
    if (pm > n) { cout << -1 << endl; return 0; }


    
    vi p;
    vector<pair<int, int>> seg;
    for (int i = 0; i < num; ++ i) {
        if ((m >> i) & 1) {
            int x = 1 << i; // 2 ^ i
            p.pb(x);
            seg.emplace_back(p.size(), p.size());
        }
    }
    
//     bool flag[];
    vector<bool> flag(n + 1, 0);
    for (auto x : p) { flag[x] = 1; }
    int s = p.size() + 1;
    for (int x = 1; x <= n; ++ x) {
        if (!flag[x]) p.pb(x);
    }
    if ((int)p.size() > s - 1) {
        seg.emplace_back(s, p.size());
    }
    
    for (int i = 0; i < n; ++ i) {
        cout << p[i] << " ";
    } cout << endl;
    
    cout << seg.size() << endl;
    for (auto &i : seg) {
        cout << i.first << " " << i.second << endl;
    }
    
} 