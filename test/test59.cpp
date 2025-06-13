// 约瑟夫环
#include<bits/stdc++.h>

using namespace std;

#define akitama return 0
#define ll long long int
#define vl vector<ll>
// 1 - 5000

int f(int n, int m) {
    return  n == 1? n : (f(n-1,m)+m-1)%n+1;
}

int cal (int n, int m, int mod) {
    int p = 0;
    for (int i = 1; i<= n; ++ i){
        p = (p + m) % i;
    }
    return p;
}

void solve() {
    // int n, k, mod; cin >> n >> k >> mod;
    // cout << cal(n, k, mod) << endl;

    int a[5001] = { 0 };
    int n, m; cin >> n >> m;
    printf("%d\n", f(n,m));
    int count = 0;

    int k = -1;
    while (count < n - 1) {
        int i = 0;
        while (i < m) {
            k = (k + 1) % n;
            if (a[k] == 0) {
                i ++;
                if (i == m) {
                    a[k] = -1;
                    count ++;
                }
            }
        }
    }
    for (int i = 0; i < n; ++ i) {
        if(a[i] == 0) {
            printf("%d\n", i + 1);
            break;
        }
    }
    return;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    akitama;
}