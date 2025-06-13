#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
const int MAXN = 100005;

void solve() {
    int n = 0, k = 0;
    cin >> n >> k;
    int flag[200] = {0};
    int num[200];
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        flag[num[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (flag[num[i]] == k) {
            cout << num[i];
            return;
        }
    }
    cout << "-1" << endl;

    
}

int prime(int n){
    if(n<=1) return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}