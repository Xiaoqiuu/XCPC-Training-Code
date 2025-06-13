#include <iostream>
#include <cmath>
#include <time.h>
using namespace std;
using ll = long long;
using ul = unsigned long long int;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
int main() 
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    //i32 num; cin >> num;
    //i32 ans = 0;
    //i32 n = num;
    const ll MOD = 1e6;
    i32 n;
    ul S = 0;
    scanf("%d", &n);
    for (i32 i = 1; i <= n; i++) {
        int factorial = 1;
        for (i32 j = 1; j <= i; j++) {
            factorial = (factorial * j % MOD);
        }
        S = (S + factorial) % MOD;
    }
    printf("Answer is %d\n", S);

    //cout << ans << endl;
    printf("Time used: %.2f\n", (double)clock() / CLOCKS_PER_SEC);
    
    return 0;
}