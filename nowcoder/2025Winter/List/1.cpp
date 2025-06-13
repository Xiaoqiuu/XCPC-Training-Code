//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;
#define i32 int
#define i64 long long
#define u64 unsigned long long
#define ld long double
#define akitama return 0

// void solve() {
//     i64 n, x;cin >> n >> x;
//     i32 target = 0;
//     while (n > 10) {
//         target = 
//         n /= 10;
//     }
// }

void solve() {
    i64 x, n;cin >> x >> n;
    i32 time = 0;
    for (int i = 1;i <= n;++ i) {
        string tmp = to_string(i);
        for (char target : tmp) {
            if(target == x + '0') {
                time ++;
            }
        }
    }
    cout << time << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    akitama;
}