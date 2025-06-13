#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define akitama return 0

void solve() {
    int n;
    cin >> n; // 输入碗的数量
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i]; // 输入碗的容量
    }

    // 排序碗的容量
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";}
    // 找到牛妹家至少一半数量碗的容量（下标为 n/2 - 1）
    
    double res = (a[n/2] + a[n/2 + 1]) / 2.0;
    
    
    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    akitama;
}
