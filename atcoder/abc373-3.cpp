//TLE
#include <iostream>
#include <cstring>
#include <cmath>
#define akitama return 0

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n;  
    cin >> n;  
    ll ans[n + 1]; // 数组大小应为n+1，但通常我们习惯从1开始索引时分配n+1个元素，或者从0开始索引分配n个元素  
                   // 这里为了保持您的原始代码风格，我们从1开始索引，但请注意这可能会导致一些未定义行为（如果n非常大）  
                   // 在实际应用中，建议使用vector或从0开始索引  
  
    for (int i = 1; i <= n; ++i) {  
        ans[i] = 0; // 初始化ans[i]为0，但实际上这个初始化是多余的，因为后面会重新赋值  
  
        ll num;  
        cin >> num;  
  
        if (num > 1) { // 只处理大于1的数  
            ll maxPower = 0;  
            ll divisor = 2;  
  
            // 寻找num的最大质因数幂次  
            while (divisor * divisor <= num) {  
                ll count = 0;  
                while (num % divisor == 0) {  
                    num /= divisor;  
                    ++count;  
                }  
                maxPower = max(maxPower, count);  
                ++divisor;  
            }  
  
            // 如果num仍然大于1，那么它本身就是一个剩余的大质数  
            if (num > 1) {  
                maxPower = max(maxPower, 1LL); // 这里其实是maxPower = 1，因为num是一个质数，但保持max的形式以与上面的代码风格一致  
            }  
  
            // 最大操作次数等于最大幂次加1  
            ans[i] = maxPower + 1;  
        }  
    }  
  
    for (int i = 1; i <= n; ++i) {  
        cout << ans[i] << endl;  
    } 
    akitama;
}
