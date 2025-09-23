#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using ll = long long int;
using namespace std;

signed main() {
    vector<set<ll>> vs(3);
    int x, y, z;
    cin >> x >> y >> z;

    vs[0] = {1, 3, 5, 7};
    vs[1] = {2, 4, 6};
    vs[2] = {10, 20};
    // int idx = distance(vs[0].begin(), vs[1].end());
    int idx = distance(vs[x].begin(), upper_bound(vs[x].begin(), vs[x].end(), z)) + 1;
    cout << idx << endl;
}