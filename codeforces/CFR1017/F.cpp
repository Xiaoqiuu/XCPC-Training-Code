#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <utility>
#include <climits>
#include <cstdlib>
#include <bitset>
#include <queue>
#include <set>
#include <cctype>
#include <iomanip>

using namespace std;

typedef long long int ll;
typedef long double ld;

#define akitama return 0
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second
#define lowbit(x) (x&(-x))

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vi> ans(n,vi(m));
    if (n == 2 && m == 2){
        cout << "1 2\n2 1\n";
    } else {
        int tot = n * m;
        vi a;
        int idx = 0;
        int cnt = tot/k;
        for(int i = 1;i<=k;++i){
            for (int j = 0;i<cnt;++j){
                a.push_back(i);
            }
        }

        
        for(int p = 0;p<2;++p){
            for(int i= 0;i<n;++i)
                for(int j=0;j<m;++j) {
                    if ((i+j)%2==p) {
                        ans[i][j] = a[idx++];
                    }
                }
        }

    }
    for (int i = 0;i<n;++i){
        for (int j=0;j<m;++j) {
            cout<<ans[i][j] << " ";
        }
        cout << endl;
    }
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    
    int _; cin >> _;
    // int _ = 1;
    
    while (_) { solve(); _--; }

    akitama;
}