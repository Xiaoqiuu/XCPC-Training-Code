#include <iostream>
#include <algorithm>
//#include <queue>
//#include <vector>
#define akitama return 0
#define pq priority_queue
#define vec vector

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

struct Fish {
    ll l, r, weight;
};//剁椒鱼头

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        ll n, x;
        cin >> n >> x;

        vec<Fish> f(n);
        for (int i = 0; i < n; ++i) {
            cin >> f[i].l >> f[i].r >> f[i].weight;
        }

        sort(f.begin(), f.end(), [](Fish a, Fish b) {
            return a.l < b.l;
        });

        ll max_weight = x;
        pq<ll> pq;
        int i = 0;

        for (ll t = f[0].l; t <= f[n-1].l; ++t) {
            ll cw = x;
            pq<ll> temp_pq = pq;

            while (i < n && f[i].l <= t) {
                if (f[i].weight <= x) {
                    pq.push(f[i].weight);
                }
                ++i;
            }

            while (!temp_pq.empty()) {
                ll top_fish = temp_pq.top();
                temp_pq.pop();
                cw += top_fish;
            }
            
            max_weight = max(max_weight, cw);
        }

        cout << max_weight << endl;
    }

    return 0;
}
