#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 统计一种括号在不交换情况下的原始匹配数
ll count_base(const string &s, char open, char close) {
    ll left = 0, matches = 0;
    for (char c : s) {
        if (c == open) {
            left++;
        } else if (c == close) {
            if (left > 0) {
                left--;
                matches++;
            }
        }
    }
    return matches;
}

// 统计一种括号总能配对的对数
ll count_possible(const string &s, char open, char close) {
    ll cnt_o = 0, cnt_c = 0;
    for (char c : s) {
        if (c == open) cnt_o++;
        else if (c == close) cnt_c++;
    }
    return min(cnt_o, cnt_c);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q; cin >> q;
    while (q --){
        ll K;
        string S;
        cin >> K >> S;

        // 三种括号类型分别计算
        ll base1 = count_base(S, '(', ')');
        ll base2 = count_base(S, '[', ']');
        ll base3 = count_base(S, '{', '}');

        ll pos1 = count_possible(S, '(', ')');
        ll pos2 = count_possible(S, '[', ']');
        ll pos3 = count_possible(S, '{', '}');

        ll rem = (pos1 - base1) + (pos2 - base2) + (pos3 - base3);
        ll add = min(rem, K);

        ll answer = base1 + base2 + base3 + add;
        cout << answer << "\n";
    }
    return 0;
}


