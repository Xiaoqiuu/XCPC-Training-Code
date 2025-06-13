#include <stdio.h>
#define sci(x) scanf("%d", &x)
#define akitama return 0

void solve() {
    int n; sci(n);
    printf("%d\n", (n*2));
}

signed main() {
    int _ = 1;
    sci(_);
    while (_--) {
        solve();
    }
    akitama;
}