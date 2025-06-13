#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        ll n, k, l;
        cin >> n >> k >> l;
        vector<ll> a(n);
        for(auto &x: a) cin >> x;
        sort(a.begin(), a.end());
        ll left=0, right=l;
        auto check = [&](ll t) -> bool{
            vector<pair<ll, ll>> intervals;
            for(auto x: a){
                ll start = max(0LL, x - t);
                ll end = x + t;
                intervals.emplace_back(start, end);
            }
            sort(intervals.begin(), intervals.end());
            vector<pair<ll, ll>> merged;
            for(auto &[s,e]: intervals){
                if(merged.empty() || s > merged.back().second){
                    merged.emplace_back(s, e);
                }
                else{
                    merged.back().second = max(merged.back().second, e);
                }
            }
            ll y_prev=0;
            for(auto &[s,e]: merged){
                if(s > y_prev +1){
                    continue;
                }
                ll y_m = max(y_prev +1, s);
                y_m = min(y_m, e);
                y_prev = y_m;
                if(y_prev +k >= l){
                    return true;
                }
            }
            return y_prev +k >= l;
        };
        while(left < right){
            ll mid = left + (right - left)/2;
            if(check(mid)){
                right = mid;
            }
            else{
                left = mid +1;
            }
        }
        cout << left *2 << "\n";
    }
}
