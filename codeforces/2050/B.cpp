#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
void solve() {
    int num;cin >> num;
    int a[num];
    ll sum = 0;
    for(int i=0;i<num;i++) {
        cin >> a[i];
        sum += a[i];
    }
    
    ll target = sum / num;
    for(int i = 1; i <= num - 2; i ++) {
        if(a[i-1] < target) {
            int diff =target - a[i-1];
            a[i-1] += diff;
            a[i+1] -= diff;
        } else if(a[i-1] > target) {
            int diff =  a[i-1] - target;
            a[i-1] -= diff;
            a[i+1] += diff;
        }
    }
    for(int i=0;i< num;i++) {
        if(a[i]!= target) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin >> t;
    while(t--) {
        solve();
        }
    return 0;
}
