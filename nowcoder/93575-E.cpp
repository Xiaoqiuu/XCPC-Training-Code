#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <climits>//int_MIN
#define akitama return 0
using namespace std;

int calculate(const vector<int>& sub) {
    int size = sub.size();
    vector<int> p_s(size + 1, 0);
    for (int i = 1; i <= size; ++i) {
        p_s[i] = p_s[i - 1] + sub[i - 1];
    }
    unordered_set<int> m_val;//前缀和最大值
    int max_n = INT_MIN;
    
    for (int i = 0; i <= size; ++i) {
        max_n = max(max_n, p_s[i]);
        m_val.insert(max_n);
    }
    return m_val.size();
}

int main() {
    int n;cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) cin >> b[i];
    int q;cin >> q;
    vector<int> res;
    for (int i = 0; i < q; ++i) {
        int l, r;cin >> l >> r;
        vector<int> sub(b.begin() + l - 1, b.begin() + r);
        int A_val = calculate(sub);
        res.push_back(A_val);
    }
    for (int ans : res) cout << ans << endl;
    akitama;
}
