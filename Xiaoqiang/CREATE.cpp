#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
// 随机生成长度为 n 的括号串
string gen_string(int n) {
    static const char brs[] = "()[]{}";
    string s;
    s.reserve(n);
    for (int i = 0; i < n; i++) {
        s += brs[rand() % 6];
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    srand((unsigned)time(NULL));
    int T = 100;              // 测试用例数量
    int maxN = 990000;      // 最大字符串长度
    cout << T << "\n";
    for (int tc = 0; tc < T; tc++) {
        int n = 1 + rand() % maxN;
        ll K = rand() % (n + 1);
        string s = gen_string(n);
        cout << K << "\n" << s << "\n";
    }
    return 0;
}
