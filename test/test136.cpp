#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

signed main() {
    std::vector<int> a = {2, 2, 5, 4, 3, 2, 1};
    sort(a.begin(), a.end());
    for (int i = 0; i < 7; ++ i) cout << a[i] << " ";cout << endl;
    // 1 2 2 2 3 4 5 
    auto it = unique(a.begin(), a.end());
    // 1 2 3 4 5 4 5
    for (int i = 0; i < 7; ++ i) cout << a[i] << " "; cout << endl;
    // 1 2 3 4 5
    for (auto i = a.begin(); i < it; ++ i) cout << *i << " "; cout << endl;
    a.erase(it, a.end());
    for (auto i : a) cout << i << " ";
}