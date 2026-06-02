#include <iostream>
#include <vector>
#include <string>

#define akitama return 0
#define ll long long int
#define ld long double

using std::cin;
using std::cout;
using std::string;

#define MAX_SIZE 100

typedef struct {
    string s;
    int num;
}Apple_Piece;

typedef struct {
    Apple_Piece ap[MAX_SIZE];
    int num;
}Apple;

void solve() {
    Apple a;
    int n; cin >> n;
    for (int i = 0; i < n; ++ i) {
        cin >> a.ap[i].s >> a.ap[i].num;
    }
    for (int i = 0; i < n; ++ i) {
        cout << a.ap[i].s << " " << a.ap[i].num << "\n";    
    }
}

signed main() {
    std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
    int _ = 1;
    // std::cin >> _;
    while (_--) {
        solve();
    }
    akitama;
}