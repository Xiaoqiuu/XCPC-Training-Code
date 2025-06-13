#include <iostream>
#include <vector>
using namespace std;

#define akitama return 0

const int N = 1e5 + 10;
bool is_prime[N]; // 素数状态
vector<int> prime; // 存素数


void isPrime(int n) {
    // 初始化bool数组
    is_prime[0] = false, is_prime[1] = false;
    for (int i = 2; i <= n; ++ i) {
        is_prime[i] = true;
    }
    
    for (int i = 2; i * i <= n; ++ i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; ++ j) {
                is_prime[j] = false;
            }
        }
    }
    
    // 存一下素数 根据题目操作找到的素数

    for (int i = 2; i <= n; ++ i) {
        if (is_prime[i]) {
            prime.push_back(i);
        }
    }
}

void solve() {
    int n;cin >> n;
    isPrime(n);
    for (auto i : prime) {
        cout << i << " ";
    }
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _ = 1;
    while (_) {
        solve();
        _--;
    }
    akitama;
}