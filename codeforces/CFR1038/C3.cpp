#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>
#include <utility>
#include <cmath>
#include <stack>
#include <queue>
#include <iomanip>
#include <numeric>
#include <bitset>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;
using ll = long long int;
using ld = long double;
using ull = unsigned long long int;
/*

*/
#define akitama return 0
/*
Author: Akitama
Date: 2025-07-19 23:40:06
Akitama Default Contest Template V2.0
*/

#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define l(x) x << 1
#define r(x) x << 1 | 1

constexpr int N = 1e5 + 7;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 0X3f3f3f3f;

struct Point {
    ll x;
    ll y;
    int id;
};

void solve() {
    int n; cin >> n;
    vector<Point> points;
    for (int i = 0; i < n;++ i) {
        ll x, y;
        cin >> x >> y;
        points.pb({x, y, i + 1});
    }

    if (n == 2) {
        cout << points[0].id << " " << points[1].id << "\n";
    }

    vector<Point> poi = points;
    sort(poi.begin(), poi.end(), [](const Point& a, const Point& b){
        if (a.x != b.x) {
            return a.x < b.x;
        }
        if (a.y != b.y) {
            return a.y < b.y;
        }
        return a.id < b.id;
    });

    vector<pii> match;
    ll sum1 = 0;
    for (int i = 0; i < n / 2; ++ i) {
        int j = n - 1 - i;
        ll dx = abs(poi[i].x - poi[j].x);
        ll dy = abs(poi[i].y - poi[j].y);
        sum1 += (dx + dy);
        match.pb({poi[i].id, poi[j].id});
    }

    vector<Point> poin = points;
    sort(poin.begin(), poin.end(), [](const Point& a, const Point& b){
        if (a.y != b.y) {
            return a.y < b.y;
        }
        if (a.x != b.x) {
            return a.x < b.x;
        }
        return a.id < b.id;
    });

    vector<pii> match2;
    ll sum2 = 0;
    for (int i = 0; i < n / 2; ++ i) {
        int j = n - 1 - i;
        ll dx = abs(poin[i].x - poin[j].x);
        ll dy = abs(poin[i].y - poin[j].y);
        sum2 += (dx + dy);
        match2.pb({poin[i].id, poin[j].id});
    }

    vector<pii>* cm = &match;
    if (sum2 > sum1) {
        cm = &match2;
    }
    for (int i = 0; i < n / 2; ++ i) {
        cout << (*cm)[i].se << " " << (*cm)[i].se << "\n";
    }
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1; cin >> _;
    while (_--){
        solve();
    }
    akitama;
}
