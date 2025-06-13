//19710 2024Shengsai R
//赛时做法
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long double m, n;cin >> m >> n;
    for (int i = 1; i <= (int)m; i++)
    n *= 2;
    n - (int)n <= 0.5? n = (int)n : n = (int)n + 1;
    //cout
    cout<< n << "\n";
    return 0;
}