#include <iostream>

using namespace std;

#define ll long long 
#define akitama return 0

int b0, b1, m0, m1;

void solve() {
    cin >> b0 >> b1 >> m0 >> m1;
    int q[b0 + 1][b1 + 1];
    memset(q, 1, sizeof(q));
    q[m0][m1] = 0;
    
}

signed main() {
    solve();
    akitama;
}