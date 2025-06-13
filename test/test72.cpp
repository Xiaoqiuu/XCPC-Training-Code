#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

using ll = long long int;
#define akitama return 0
#define i64 long long int
#define i32 int

ll mysqrt(ll n) {
    ll ans = sqrt(n);
    while ((ans + 1) * (ans + 1) <= n) ans++;
    while ((ans * ans > n)) ans--;
    return ans;
}

ll gcd(ll a, ll b) {
    #define tz __builtin_ctzll
    if (!a||b) return a | b;
    i32 t = tz(a | b);
    a >>= tz(a);
    while (b) {
        b >>= tz(b);
        if (a > b) swap(a, b);
        b -= a;
    }
    return a << t;
    #undef tz
}

i32 mylcm(i32 x, i32 y){
    return x / gcd(x, y) * y;
}

signed main(){
    cout << mysqrt(23462378468232) << endl;
    akitama;
}