#include <bits/stdc++.h>
using namespace std;

#define i64 long long
#define ld long double
#define akitama return 0

i64 safePow(i64 base, int exp) {
    i64 result = 1;
    for(int i = 0; i < exp; i++){
        if(result > LLONG_MAX / base) return LLONG_MAX;
        result *= base;
    }
    return result;
}

void solve() {
    i64 n, m;
        cin >> n >> m;
        if(m == 1) {
            cout << 1 << "\n";
            continue;
        }
        double ratio = 0.0;
        if(n > 1) {
            ratio = log((ld)n) / log((ld)m);
        }
        i64 k0 = (i64)floor(ratio);
        if(k0 < 1) k0 = 1;
        vector<i64> cans;
        cans.push_back(k0);
        if(k0 - 1 >= 1) cans.push_back(k0 - 1);
        cans.push_back(k0 + 1);
        i64 ans = 1;
        i64 bes = LLONG_MAX;
        for(i64 c : cans){
            if(c < 1) continue;
            i64 val = safePow(m, (int)c);
            i64 dist = llabs(val - n);
            if(dist < bes){
                bes = dist;
                ans = c;
            } else if(dist == bes && c < ans) {
                ans = c;
            }
        }
        cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin >> T;
    while(T--){
        solve();
    }
    akitama;
}
