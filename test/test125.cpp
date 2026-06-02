#include <iostream>
#include <numeric>

using std::cin;
using std::cout;

#define akitama return 0
#define ll long long int
#define endl '\n'

signed main() {
    long long int n, m;
    cin >> n >> m;
    cout << std::lcm(n, m) << endl;
    akitama;
}