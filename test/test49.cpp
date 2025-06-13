#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long int
#define akitama return 0

#define vl vector<int>

signed main() {

    vl a = {1, 3, 5, 7, 9};
    vl b = {2, 4, 6, 8, 10};
    vl c(10);

    // merge(a, a+5, b, b+5, c.begin());
    merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());

    for (auto i : c) cout << i << " ";`
    cout << endl;

    akitama;
}