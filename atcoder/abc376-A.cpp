//Written By Akitama 2024.10
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define akitama return 0;
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n, c;cin >> n >> c;
    int a[n + 1];
    int ans = 1;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int tmp = a[1];
    for (int i = 2; i <= n; i++) {
        if(a[i] - tmp < c) continue;
        else {
            ans ++;
            tmp = a[i];
        }
    }
    cout << ans << endl;
    akitama;
}