#include<iostream>
#include<cstring>
using namespace std;

#define akitama return 0
#define ll long long

const int MAXN = 1001;
int a[MAXN], b[MAXN], c[MAXN], sum[MAXN];

void mul() {
    memset(c, 0, sizeof(c));
    for (int i = 1000; i >= 0; --i) {
        for (int j = 1000; j >= 0; --j) {
            if (a[i] && b[j]) c[i + j - 1000] += a[i] * b[j];
        }
    }
    for (int i = 1000; i > 0; --i) {
        if (c[i] >= 10) {
            c[i - 1] += c[i] / 10;
            c[i] %= 10;
        }
    }
}

void add() {
    for (int i = 1000; i >= 0; --i) {
        sum[i] += a[i];
        if (sum[i] >= 10) {
            sum[i - 1] += sum[i] / 10;
            sum[i] %= 10;
        }
    }
}

void solve() {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    memset(sum, 0, sizeof(sum));
    a[1000] = 1;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        memset(b, 0, sizeof(b));
        int x = i, idx = 1000;
        while (x) {
            b[idx--] = x % 10;
            x /= 10;
        }
        mul();
        memcpy(a, c, sizeof(a));
        add();
    }
    int start_idx = 0;
    while (start_idx < 1001 && sum[start_idx] == 0) start_idx++;
    for (int i = start_idx; i < 1001; ++i) cout << sum[i];
    cout << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    solve();
    akitama;
}
