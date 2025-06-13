#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void solve(int n) {
    vector<int> perm(n);
    int k = 0;

    // 交替放置较大的数和较小的数
    int large = n, small = 1;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) { // 偶数索引放置较大的数
            perm[i] = large--;
        } else { // 奇数索引放置较小的数
            perm[i] = small++;
        }
    }

    // 计算k的最大值
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) { // 偶数索引执行按位或运算
            k |= perm[i];
        } else { // 奇数索引执行按位与运算
            k &= perm[i];
        }
    }

    // 输出结果
    cout << k << '\n';
    for (int i = 0; i < n; ++i) {
        cout << perm[i] << (i == n - 1 ? "\n" : " ");
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}

0000 0001
0000 0010
0000 0100
0000 0101
0000 0110
0000 0111
0000 1000
0000 1001
0000 1010
0000 1011
0000 1100
0000 1101
0000 1110
0000 1111
0001 0000
0001 0001
0001 0010
0001 0011