#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define pl 2 * p
#define pr pl | 1
const int N = 1e5 + 5;
int n, k;
// int a[1000005], ans[1000005];
// bool used[1000005];
int ans[N], f[N];

struct Node {
    int id, val;
    Node() { id = val = 0; }
} Zero;

bool operator<(const Node x, const Node y) {
    if (x.val == y.val) return x.id > y.id;
    return x.val < y.val;
}

struct SegmentTree {
    int l, r;
    Node max1, max2;
} tree[4000005];

void pushUp(int p) {
    vector<Node> nodes = {tree[p<<1].max1, tree[p<<1].max2, tree[p<<1|1].max1, tree[p<<1|1].max2};
    sort(nodes.begin(), nodes.end());
    tree[p].max1 = nodes.back();
    for (int i = nodes.size()-2; i >= 0; i--) {
        if (nodes[i].val != nodes[i+1].val) {
            tree[p].max2 = nodes[i];
            break;
        }
    }
}

void build(int p, int l, int r) {
    tree[p].l = l;
    tree[p].r = r;
    if (l == r) {
        tree[p].max1 = {l, a[l]};
        tree[p].max2 = Zero;
        return;
    }
    int mid = (l + r) >> 1;
    build(p<<1, l, mid);
    build(p<<1|1, mid+1, r);
    pushUp(p);
}

void modify(int p, int pos) {
    if (tree[p].l == tree[p].r) {
        tree[p].max1 = Zero;
        tree[p].max2 = Zero;
        return;
    }
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (pos <= mid) modify(p<<1, pos);
    else modify(p<<1|1, pos);
    pushUp(p);
}

void query(int p, int l, int r, Node& res1, Node& res2) {
    if (tree[p].l >= l && tree[p].r <= r) {
        vector<Node> nodes = {res1, res2, tree[p].max1, tree[p].max2};
        sort(nodes.begin(), nodes.end());
        res1 = nodes.back();
        for (int i = nodes.size()-2; i >= 0; i--) {
            if (nodes[i].val != nodes[i+1].val) {
                res2 = nodes[i];
                break;
            }
        }
        return;
    }
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (l <= mid) query(p<<1, l, r, res1, res2);
    if (r > mid) query(p<<1|1, l, r, res1, res2);
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    build(1, 1, n);
    
    for (int i = 1; i <= n; i++) {
        Node m1 = Zero, m2 = Zero;
        query(1, i, min(i + k, n), m1, m2);
        
        if (m1.val == ans[i-1]) {
            if (m2.val) {
                ans[i] = m2.val;
                modify(1, m2.id);
                k -= (m2.id - i);
            }
        } else if (m1.val) {
            ans[i] = m1.val;
            modify(1, m1.id);
            k -= (m1.id - i);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i] ? ans[i] : -1);
    }
    return 0;
}