#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define akitama return 0

void solve() {
    int n;
        cin >> n;
        vector<ll> a(n);
        for(auto &x: a) cin >> x;
        ll current_sum = 0;
        for(auto x: a) current_sum += x;
        ll max_sum = current_sum;
        while(n >1){
            ll sum_diff = a[n-1] - a[0];
            ll sum_rev_diff = a[0] - a[n-1];
            if(sum_diff >= sum_rev_diff){
                max_sum = max(max_sum, sum_diff);
                vector<ll> b(n-1);
                for(int i=0;i<n-1;i++) b[i] = a[i+1] - a[i];
                a = b;
                current_sum = sum_diff;
            }
            else{
                max_sum = max(max_sum, sum_rev_diff);
                reverse(a.begin(), a.end());
                vector<ll> b(n-1);
                for(int i=0;i<n-1;i++) b[i] = a[i+1] - a[i];
                a = b;
            }
            n--;
        }
        cout << max_sum << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin >> t;
    while(t--){
        solve();
    }
    akitama;
}