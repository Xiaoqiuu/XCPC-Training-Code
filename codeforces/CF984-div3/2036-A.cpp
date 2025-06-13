#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define akitama return 0
using ll = long long;

void solve() {
    int len;cin >> len;
    int a[len];
    bool flag = true;
    for(int i = 0; i < len; i++) {
        cin >> a[i];
        if(i) {
            if(abs(a[i] - a[i - 1])!=5 && abs(a[i] - a[i - 1])!= 7)
            flag = false;
        }
    }
    if(flag)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin >> t;
    while(t --) {
        solve();
    }
    akitama;
}