#include <bits/stdc++.h>

using namespace std;
 
#define ll long long int
#define akitama return 0

int main() {
    int m, n; cin >> m >> n;
    int a[m + 1][n + 1] = { 0 };
    int t = 1, b = m, l = 1, r = n;
    int num = 1;
    while (t <= b && l <= r) {
        for (int i = l; i <= r; ++ i) {
            a[t][i] = num++;
        } t++;
        for (int i = t; i <= b; ++ i) {
            a[i][r] = num++;
        } r--;
        if (t <= b) {
            for (int i = r; i >= l; -- i) {
                a[b][i] = num++;
            } b--;
        }
        if (l <= r) {
            for (int i = b; i >= t; -- i) {
                a[i][l] = num++;
            } l ++;
        }
    }
    // cout << "   ";
    for (int i = 1; i <= m; ++ i) {
        for (int j = 1; j <= n; ++ j) {
            cout << setw(4) << a[i][j];
        } cout << endl;
    }

    akitama;
}
