#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;
#define akitama return 0
#define ll long long int
#define vl vector<ll>
#define mpll map<ll, ll>

int n, r, c;

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    cin >> n >> r >> c;
    string s; cin >> s;
    string ans = "";
    set<pair<int,int>> st;
    st.insert({0, 0});

    for (int t = 0; t < n; t ++){
        set<pair<int,int>> st1;
    for (auto& pos : st) {
        int r = pos.first;
        int c = pos.second;
        if (s[t] == 'N') {
            st1.insert({r-1,c});
        } else if (s[t] == 'S'){
            st1.insert({r+1,c});
        } else if (s[t] == 'E'){
            st1.insert({r,c+1});
        } else if (s[t] == 'W'){
            st1.insert({r,c-1});
        }
    }

    if (!st.count({0, 0})) st1.insert({0, 0});
    st = st1;
    if (st.count({r, c})) ans += "1";
    else ans += "0";
    }
    cout << ans << endl;
    akitama;
}
// 1 1 1 2 3 4 4 