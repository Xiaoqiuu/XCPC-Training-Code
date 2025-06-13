#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <bit>
#define akitama return 0;
using namespace std;
using ll = long long int;
/*
    使用非DFS
*/

#define akitama return 0

void solve() {
    int n; cin >> n;
    vector<unsigned int> nums(n);
    for (int i = 0; i < n; ++ i) {
        cin >> nums[i];
        //bitset<32> binary(nums[i]);
        //cout << binary.count() << " ";
        cout << popcount(nums[i]) << endl;
    }
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; // cin >> _;
    while (_--) {
        solve();
    }
    akitama;
}

// int dfs(int x, int y) {
//     x==n? return a[x][y]:
//     f[x][y] + 
// }

// int main() {
//     int n;cin >> n;
//     int a[n + 1][n + 1];
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= i; j++)
//             cin >> a[i][j]
//     int user = a[1][1], i = 1, j = 1;
//     while (i < n && j < n)
//         a[i + 1][j] < a[i + 1][j + 1]? (user += a[i + 1][j + 1], j++, i++) : (user += a[i + 1][j], i ++);
//     cout << user << endl;
//     akitama;
// }