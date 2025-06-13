#include <bits/stdc++.h>
//#include <iostream>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define akitama return 0

void solve() {
    int n, a, b;cin >> n >> a >> b;
    if(abs(a-b)%2==1) {
        cout << "NO"<< endl;
    } else {
        cout << "YES" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin >> t;
    while(t--) {
        solve();
    }
    akitama;
}