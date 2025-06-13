2024ICPC武汉邀请赛 VP 记录
=======

明天报名25武汉邀请赛，心血来潮VP了一场去年的邀请赛，感觉努努力能拿铜（？

# I

一种Cf EDU A题的感觉 手速够快就行。

#### 思路

从左往右遍历一遍，遇到连续的1序列就计数一次。

#### 代码

```cpp
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <climits>
#include <utility>

using namespace std;

#define akitama return 0
#define ll long long
#define ull unsigned long long int
#define vi vector<int>
#define vll vector<ll>

void solve() {
    string s; cin >> s;
    int ans = 0;
    bool flag = false;
    for (int i = 0; i < s.size(); ++ i) {
        if (s[i] == '1') {
            flag = true;
        }
        if (flag == true && s[i] == '0') {
            ans ++;
            flag = false;
        }
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1;
    //cin >> _;
    while (_) {
        solve();
        _--;
    }
    akitama;
}
```

# K

K题卡了几回（主要原因还是自己读题和分析很菜）。

#### 思路

异或和的性质就是，当二进制位上的1的数量为偶数的时候，异或和为0。
观察数的二进制形式：
```
0000 // 0
0001 // 1
0010 // 2
0011 // 3

0100 // 4
0101 // 5
0110 // 6
0111 // 7
```

#### 代码

```cpp
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <climits>
#include <utility>

using namespace std;

#define akitama return 0
#define ll long long
#define ull unsigned long long int
#define vi vector<int>
#define vl vector<ll>
#define endl '\n'

void solve() {
    int n; cin >> n;
    if (n == 1) {
        cout << "Fluttershy" << endl; return;
    } else if (n == 2 | n == 3) {
        cout << "Pinkie Pie" << endl; return; }
        else {
            if((n - 3)% 4 == 1 || (n - 3) % 4 == 2) {
                cout << "Fluttershy" << endl;
            } else {
                cout << "Pinkie Pie" << endl;
            }
        }
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _;
    cin >> _;
    while (_) {
        solve();
        _--;
    }
    akitama;
}
```

# 其他题目持续补题(解)中