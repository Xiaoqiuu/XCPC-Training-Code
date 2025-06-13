#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

using ll = long long int;
#define akitama return 0
#define vi vector<int>

signed main() {
    int n, k;
    cin >> n >> k;
    vi a(n, 0);
    for (auto &i : a) cin >> i;
    int ans = INT_MAX;
    for (auto &num : a) {
        if (k%num) continue;
        else {
            ans = min(ans, k/num);
        }
    }
    cout << ans << endl; 
    akitama;
}