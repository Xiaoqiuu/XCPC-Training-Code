/*
    线段树使用实例代码
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <utility>
using namespace std;

// #define akitama return 0
#define ll long long int

/*
    Akitama's templates
    线段树😯
    Created Time : 2025/04/24 01:03
*/
#define akitama return 0

template<class T> struct Segt {
    struct node {
        int l , r;
        T w, rmq, lazy;
    };
    vector<T> w;
    vector<node> t;

    Segt() {}
    Segt(int n) { init(n); }
    Segt(vector<int> in) {
        int n = in.size() - 1;
        w.resize(n + 1);
        for (int i = 1; i <= n; ++ i) {
            w[i] = in[i];
        }
        init(in.size() - 1);
    }
    #define GL (k << 1)
    #define GR (k << 1 | 1)
    void init(int n) {
        w.resize(n + 1);
        t.resize(n * 4 + 1);
        auto build = [&](auto self, int l, int r, int k = 1) {
            if (l == r) {
                t[k] = { l, r, w[l], w[l], -1 };
                return;
            }
            t[k] = { l, r, 0, 0, -1 };
            int mid = (l + r) / 2;
            self(self, l, mid, GL);
            self(self, mid+1, r, GR);
            pushup(k);
        };
        build(build, 1, n);
    }
    void pushdown(node& p, T lazy) {
        p.w += (p.r - p.l + 1) * lazy;
        p.rmq += lazy;
        p.lazy += lazy;
    }
    void pushdown(int k) {
        if (t[k].lazy == -1) return;
        pushdown(t[GL], t[k].lazy);
        pushdown(t[GR], t[k].lazy);
        t[k].lazy = -1;
    }
    void pushup(int k) {
        auto pushup = [&](node& p, node& l, node& r) {
            p.w = l.w + r.w;
            p.rmq = min(l.rmq, r.rmq);
        };
        pushup(t[k], t[GL], t[GR]);
    }
    void modify(int l,int r, T val, int k = 1) {
        if (l <= t[k].l && t[k].r <= r) {
            pushdown(t[k], val);
            return;
        }
        pushdown(k);
        int mid = (t[k].l + t[k].r) / 2;
        if (l <= mid) modify(l, r, val, GL);
        if (r > mid) modify(l, r, val, GR);
        pushup(k);
    }
    T rmq(int l, int r, int k = 1) {
        if (l <= t[k].l && t[k].r <= r) {
            return t[k].rmq;
        }
        pushdown(k);
        int mid = (t[k].l + t[k].r) / 2;
        T ans = numeric_limits<T>::max(); // ::lowest();
        if (l <= mid) ans = min(ans, rmq(l, r, GL));
        if (mid < r) ans = min(ans, rmq(l, r, GR));
        return ans;
    }
    T ask(int l, int r, int k = 1) {
        if (l <= t[k].l && t[k].r <= r) {
            return t[k].w;
        }
        pushdown(k);
        int mid = (t[k].l + t[k].r) / 2;
        T ans = 0;
        if (l <= mid) ans += ask(l, r, GL);
        if (mid < r) ans += ask(l, r, GR);
        return ans;
    }

    /* DEBUG */
    void debug(int k = 1) {
        cout << "[" << t[k].l << " , " << t[k].r << "]: ";
        cout << "w : " << t[k].w << ", ";
        cout << "Min = " << t[k].rmq << ", ";
        cout << "lazy = " << t[k].lazy << ", ";
        cout << endl;
        if (t[k].l == t[k].r) return;
        debug(GL), debug(GR); 
    }
};

void solve() {
    // 示例使用代码
    vector<int> arr = {0, 1, 3, 5, 7, 9, 11}; // 下标从1开始
    
    // 创建线段树
    Segt<int> seg(arr);
    
    // 查询区间和
    cout << "Sum of [2,5]: " << seg.ask(2, 5) << endl; // 3+5+7+9=24
    
    // 查询区间最小值
    cout << "Min of [3,6]: " << seg.rmq(3, 6) << endl; // min(5,7,9,11)=5
    
    // 区间加法
    seg.modify(4, 6, 2); // 给第4到6个元素加2
    
    // 再次查询
    cout << "After modify:" << endl;
    cout << "Sum of [2,5]: " << seg.ask(2, 5) << endl; // 3+(5)+(7+2)+(9+2)=28
    cout << "Min of [3,6]: " << seg.rmq(3, 6) << endl; // min(5,7+2,9+2,11+2)=5
    
    // 调试输出
    cout << "\nDebug info:" << endl;
    seg.debug();
}

signed main() {
    solve();
    akitama;
}