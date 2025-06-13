#include <bits/stdc++.h>
using namespace std;

#define akitama return 0
#define ll long long

ll val[3][3][3];
int g1, g2;

inline int cti(char c) { return c - 'a'; }
inline char itc(int i) { return 'a' + i; }

struct DP {
    int A, B, C, BD, CD;
    vector<ll> dp;
    vector<int> ch;

    DP(int A_, int B_, int C_) : A(A_), B(B_), C(C_) {
        int sz = (A+1) * (B+1) * (C+1) * 9;
        dp.assign(sz, LLONG_MIN);
        ch.assign(sz, -1);
    }
    
    inline int idx(int a, int b, int c, int st) {
        return (((a * (B+1) + b) * (C+1) + c) * 9) + st;
    }
    
    ll f(int a, int b, int c, int st) {
        int p = idx(a, b, c, st);
        if(dp[p] != LLONG_MIN) return dp[p];
        if(a == 0 && b == 0 && c == 0) {
            int x = st / 3, y = st % 3;
            return dp[p] = val[x][y][g1] + val[y][g1][g2];
        }
        int x = st / 3, y = st % 3;
        ll mx = -LLONG_MAX;
        int opt = -1;
        if(a > 0) {
            ll t = val[x][y][0] + f(a-1, b, c, y*3+0);
            if(t > mx) { mx = t; opt = 0; }
        }
        if(b > 0) {
            ll t = val[x][y][1] + f(a, b-1, c, y*3+1);
            if(t > mx) { mx = t; opt = 1; }
        }
        if(c > 0) {
            ll t = val[x][y][2] + f(a, b, c-1, y*3+2);
            if(t > mx) { mx = t; opt = 2; }
        }
        ch[p] = opt;
        return dp[p] = mx;
    }
    
    string r(int a, int b, int c, int st) {
        string res;
        while(a > 0 || b > 0 || c > 0) {
            int p = idx(a, b, c, st);
            int l = ch[p];
            res.push_back(itc(l));
            int y = st % 3;
            st = y * 3 + l;
            if(l == 0) a--;
            else if(l == 1) b--;
            else c--;
        }
        return res;
    }
};

pair<ll, string> solve(int f1, int f2, int A, int B, int C) {
    DP d(A, B, C);
    int st = f1 * 3 + f2;
    ll sc = d.f(A, B, C, st);
    string seq = d.r(A, B, C, st);
    return {sc, seq};
}

void solve() {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        solve();
    }
    akitama;
}