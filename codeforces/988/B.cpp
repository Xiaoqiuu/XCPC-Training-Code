#include <iostream>
#include <algorithm>
using namespace std;

void solve() {
    int n_1;
    cin >> n_1;
    int num[n_1];
    for (int i = 0; i < n_1; i++)
        cin >> num[i];
    
    sort(num, num + n_1);

    for (int i = 0; i < n_1 - 1; i++) {
        int target = (n_1 - 2) / num[i];
        if ((n_1 - 2) % num[i] == 0 && binary_search(num + i + 1, num + n_1, target)) {
            cout << num[i] << " " << target << endl;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

