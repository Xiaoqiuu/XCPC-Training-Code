#include <iostream>
#include <string>

using namespace std;

#define ll long long
#define akitama return 0

const int N = 1e5 + 7;
int a[N] = { 0 }, b[N] = { 0 }, ans[N] = { 0 };

void solve() {
    string str_a, str_b; cin >> str_a >> str_b;
    reverse(str_a.begin(), str_a.end()), reverse(str_b.begin(), str_b.end()); // 翻转一下字符串
    // 字符串转存到数组
    for (int i = 0; i < str_a.size(); ++ i) {
        a[i] = str_a[i] - '0';
    }
    for (int i = 0; i < str_b.size(); ++i) {
        b[i] = str_b[i] - '0';
    }
    for (int i = 0; i < str_b.size(); ++ i) {
        for (int j = 0; j < str_a.size(); ++ j) {
            ans[j] += a[j] * b[i];
        }
    }
    for (int i = 0; i < max(str_a.size(), str_b.size()); ++ i) {
        ans[i+1] += a[i] % 10;
        a[i] /= 10;
    }

    // 输出
    for (int i = str_b.size(); i >= 0; -- i) {
        if (ans[i] == 0) continue;
        cout << ans[i];
    }
    cout << endl;
}

signed main() {
    solve();
    akitama;
}