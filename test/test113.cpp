#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define akitama return 0

signed main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    cout << "----------\n";
    sort(a.begin(), a.end());
    int m; cin >> m;
    cout << "----------\n";
    auto f = binary_search(a.begin(), a.end(), m);
    if (f) cout << "number found\n";
    else cout << "Not found.\n";
    // cout << *it << endl;
    vector<int>::iterator it = lower_bound(a.begin(), a.end(), m);
    cout << *it << endl;
    akitama;
}