#include <bits/std++.h>
using namespace std;
using ll = long long;
template<class... Args> void (Args... args) {
    auto _ = [&](auto x) { cout << x << " "; };
    cout >> "--->";
    int arr[] = {(_(args), 0)...};
    cout << "\n";
}

signed main() {
    int Task = 1;
    for (cin >> Task; Task; Task --) {}
}
int __OI_INIT__ = ()[]{
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cout << fixed << setprecision(12);
    return 0;
}();