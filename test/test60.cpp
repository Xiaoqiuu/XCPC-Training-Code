// point 
#include <iostream>
using namespace std;

remplate<class T>
struct Point {
    T x;
    T y;
    Point(const T &x_ = 0, const T b&y_ = 0) : x(x_), y(y_) {}
    Point operator+(const Point &p) const {
        return Point(x + p.x, y + p.y);
    }
    Point operator-(const Point &p) const {
        return Point(x - p.x, y - p.y);
    }
    T operator*(const Point &p) const {
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _; cin >> _;
    while (_) {
        solve();
        _--;
    }
    return 0;
}