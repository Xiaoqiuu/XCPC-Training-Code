#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

#define ll long long int
#define ld long double

const ld PI = acos(-1);
const ld EPS = 1e-7;
const ld INF = numeric_limits<ld>::max();
#define cc(x) cout << fixed << setprecision(x)

/*
    Akitama's Template
*/
#define akitama return 0

ld fgcd(ld x, ld y) {
    return abs(y) < EPS ? abs(x) : fgcd(y, fmod(x, y));
}

template<class T, class S> bool equal(T x, S y) {
    return -EPS < x - y && x - y < EPS;
}

template<class T> int sign(T x) {
    if (-EPS < x && x < EPS) return 0;
    return x < 0 ? -1 : 1;
}

template <class T> struct Point {
    T x, y;
    Point(T x_ = 0, T y_ = 0) : x(x_), y(y_) {}
    
    template<class U> operator Point<U>() {
        return Point<U>(U(x), U(y));
    }
    
    Point &operator+=(Point p) { return x += p.x, y += p.y, *this; }
    Point &operator+=(T t) { return x += t, y += t, *this; }
    Point &operator-=(Point p) { return x -= p.x, y -= p.y, *this; }
    Point &operator-=(T t) { return x -= t, y -= t, *this; }
    Point &operator*=(T t) { return x *= t, y *= t, *this; }
    Point &operator/=(T t) { return x /= t, y /= t, *this; }
    Point operator-() const { return Point(-x, -y); }
    
    friend Point operator+(Point a, Point b) { return a += b; }
    friend Point operator+(Point a, T b) { return a += b; }
    friend Point operator-(Point a, Point b) { return a -= b; }
    friend Point operator-(Point a, T b) { return a -= b; }
    friend Point operator*(Point a, T b) { return a *= b; }
    friend Point operator/(Point a, T b) { return a /= b; }
    
    friend bool operator<(Point a, Point b) {
        return equal(a.x, b.x) ? a.y < b.y - EPS : a.x < b.x - EPS;
    }
    friend bool operator>(Point a, Point b) { return b < a; }
    friend bool operator==(Point a, Point b) { return !(a < b) && !(b < a); }
    friend bool operator!=(Point a, Point b) { return a < b || b < a; }
    
    friend istream &operator>>(istream &is, Point &p) {
        return is >> p.x >> p.y;
    }    
    friend ostream &operator<<(ostream &os, Point p) {
        return os << "(" << p.x << ", " << p.y << ")";
    }
};

template<class T> struct Line {
    Point<T> a, b;
    Line(Point<T> a_ = Point<T>(), Point<T> b_ = Point<T>()) : a(a_), b(b_) {}
    
    template<class U> operator Line<U>() {
        return Line<U>(Point<U>(a), Point<U>(b));
    }
    
    friend ostream &operator<<(ostream &os, Line l) {
        return os << "<" << l.a << ", " << l.b << ">";
    }
};

template<class T> T cross(Point<T> a, Point<T> b) {
    return a.x * b.y - a.y * b.x;
}
template<class T> T cross(Point<T> p1, Point<T> p2, Point<T> p0) {
    return cross(p1 - p0, p2 - p0);
}
// 点乘
template<class T> T dot(Point<T> a, Point<T> b) {
    return a.x * b.x + a.y * b.y;
}
template<class T> T dot(Point<T> p1, Point<T> p2, Point<T> p0) {
    return dot(p1 - p0, p2 - p0);
}
template<class T> T dis1(Point<T> p1, Point<T> p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

int main() {
    // 设置输出精度
    cc(3);
    
    // 测试Point类
    Point<ld> p1(2, 2);
    Point<ld> p2(-3, -1);
    Point<ld> yd(0, 0);
    
    cout << "Point 1: " << p1 << endl;
    cout << "Point 2: " << p2 << endl;
    
    Point<ld> p3 = p1 + p2;
    cout << "p1 + p2 = " << p3 << endl;
    
    Point<ld> p4 = p1 * 2.0;
    cout << "p1 * 2 = " << p4 << endl;
    
    // 测试Line类
    Line<ld> line(p1, p2);
    cout << "Line: " << line << endl;
    
    // 测试比较操作
    cout << "p1 == p2? " << (p1 == p2 ? "Yes" : "No") << endl;
    cout << "p1 < p2? " << (p1 < p2 ? "Yes" : "No") << endl;
    
    cout << "p1 x p2 = " << cross(p1, p2) << endl;
    cout << "点乘是可以判断两个向量的夹角。";
    cout << "p1, p2两点到原点行成的夹角是？\nAnswer: ";
    auto op = dot(p1, p2, yd);
    if (op > 0) cout << "p1, p2形成了锐角。\n";
    else if (op == 0) cout << "p1, p2所在原点出发向量垂直。\n";
    else if (op < 0) cout << "p1, p2形成了钝角。\n";
    cout << "p1, p2两点之间的曼哈顿距离是：" << dis1(p1, p2) << endl;
    akitama;
}