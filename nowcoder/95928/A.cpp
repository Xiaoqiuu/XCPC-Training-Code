#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <utility>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
void solve() {
    int n, ans = 0;cin >> n;
    char ch[n + 1];cin >> ch;
    for(int i = 0; i < n; ++ i) {
        if(ch[i] == '0') ans ++;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t_89;t_89 = 1;
    while(t_89 --) {
        solve();
    }
    return 0;
}