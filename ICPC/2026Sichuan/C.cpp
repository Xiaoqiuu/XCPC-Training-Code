#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

// 线段树维护 dp 区间最小值
struct SegmentTree {
    int n;
    vector<int> tree;

    SegmentTree(int n) : n(n), tree(4 * (n + 1), INF) {}

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid) update(2 * node, l, mid, idx, val);
        else update(2 * node + 1, mid + 1, r, idx, val);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return INF;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return min(query(2 * node, l, mid, ql, qr),
                   query(2 * node + 1, mid + 1, r, ql, qr));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;

    // beaten_by[i] 存储所有克制 i 的精灵编号
    vector<vector<int>> beaten_by(n + 1);
    for (int i = 1; i <= n; ++i) {
        int s;
        cin >> s;
        beaten_by[i].resize(s);
        for (int j = 0; j < s; ++j) {
            cin >> beaten_by[i][j];
        }
        sort(beaten_by[i].begin(), beaten_by[i].end());
    }

    vector<int> a(m + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
    }

    // 判断 A 是否克制 B
    auto beats = [&](int A, int B) -> bool {
        return binary_search(beaten_by[B].begin(), beaten_by[B].end(), A);
    };

    // 记录精灵 X 连续克制区间的起始点和上一个成功克制的位置
    vector<int> start_pos(n + 1, 1);
    vector<int> last_pos(n + 1, 0);

    SegmentTree seg(m);
    vector<int> dp(m + 1, INF);

    dp[0] = 0;
    seg.update(1, 0, m, 0, 0);

    for (int i = 1; i <= m; ++i) {
        // 情况 1: 单独一只精灵消灭 a[i]
        dp[i] = dp[i - 1] + 1;

        // 情况 2: 精灵 X 连续克制到 a[i-1]，并在 a[i] 处结束
        if (i >= 2) {
            int prev = a[i - 1];
            int curr = a[i];

            // 遍历所有能克制 a[i-1] 的精灵 X
            for (int X : beaten_by[prev]) {
                if (last_pos[X] == i - 2) {
                    // 连续段延续
                } else {
                    // 连续段断开，重新从 i-1 开始
                    start_pos[X] = i - 1;
                }
                last_pos[X] = i - 1;

                // 检验 X 对阵 curr(a[i]) 是否合法：
                // X 必须不被 curr 单向克制，即：X 克制 curr 或者 curr 不克制 X
                bool X_beats_curr = beats(X, curr);
                bool curr_beats_X = beats(curr, X);

                if (X_beats_curr || !curr_beats_X) {
                    int L = max(0, start_pos[X] - 1);
                    int R = i - 2;
                    if (L <= R) {
                        int min_val = seg.query(1, 0, m, L, R);
                        if (min_val != INF) {
                            dp[i] = min(dp[i], min_val + 1);
                        }
                    }
                }
            }
        }

        seg.update(1, 0, m, i, dp[i]);
    }

    cout << dp[m] << "\n";

    return 0;
}