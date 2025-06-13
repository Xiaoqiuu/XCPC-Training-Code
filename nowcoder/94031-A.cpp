#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int n,ans = 0;cin >> n;

    bool flag[n + 1];
    for (int i = 1; i <= n; i++) {
        char c;cin >> c;
        if (c == '1') {
            flag[i] = true;
        } else {
            flag[i] = false;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (flag[i])
            ans++;
    }
    if(ans == n/2) cout << -1 << endl;
    else if (ans < n/2) {
        int _ans = 0;
        for (int i = 1; i < n; i++) {
            if (flag[i] != flag[i+1]) _nas ++;
        } cout << _ans << endl;
    } 
    return 0;
}