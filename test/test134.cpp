#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <bitset>
#include <set>
#include <queue>
#include <climits>
#include <cstdbool>

using std::vector;
using std::cin;
using std::string;

using ll = long long int;

#define vi vector<int>
#define vll vector<ll>
#define akitama return 0

void solve();

constexpr int MOD = 998244353;
constexpr int INF = 0x3f3f3f3f;

#define MaxSize 1000
#define count_t int

typedef struct Dw {
    count_t cnt[MaxSize];    
    Dw* nxt_Dw;
}Dw, *Dw_ptr;

typedef int dw_sum_t;
typedef int dw_i_t;

/*
********************
DEBUG FOR DW
********************
*/

// #define DEBUG_DW


void Dw_Sort(vector<Dw> &vd) {
    dw_i_t len = vd.size();
    sort(vd.begin(), vd.end(), [](const Dw& a,const Dw& b){
        if (a.cnt[0] == b.cnt[0]) {
            if (a.nxt_Dw != NULL) return &a < &b;
            else return &b < &a;
        } return &b < &a;
    });

    #ifdef DEBUG_DW 
    std::cout << "sorted num of Dw_Sort: " << len;
    #endif
}

Dw* CheckNode(Dw& D){
    
    for (int i = 0; i < MaxSize; ++ i) {

    }
    return &D;
}

signed main() {
    std::cin.tie(nullptr)->
    std::ios::sync_with_stdio(false);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    akitama;
}

void solve() {

}