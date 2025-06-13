#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
using ld = long double;
#define akitama return 0
#define INF 1e18
#define MOD 1000000007

ld S = 0;
ll ans1 = 0, ans2 = 0, ans3 = 0;

inline int gcd(int a, int b)
{
	if (a % b == 0) return b;
	else return gcd(b, a % b);
}

inline ll lcm(int a, int b)
{
	ll temp = a * b;
	temp = temp / gcd(a, b);
	return temp;
}

void solve() {
    int num;cin >> num;
    int H[num + 1];
    for (int i = 1; i <= num; i++) {
        cin >> H[i];
    }
    for(int i = 1; i <= num - 2; i++) {
        for(int j = i+1; j <= num - 1; j++) {
            for(int k = j+1; k <= num; k++) {
                ld tmp = H[i]*H[j]*H[k]*1.0;
                tmp *= lcm(H[i], lcm(H[j], H[k]))/(lcm(H[i], H[j]) * lcm(H[j], H[k])*lcm(H[i], H[k]));
                cout << tmp << endl;
                if(tmp > S) {
                    S = tmp;
                    ans1 = i, ans2 = j, ans3 = k;
                }
            }   
        }
    }
    
    cout << ans1 << " " << ans2 << " " << ans3 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    akitama;
}