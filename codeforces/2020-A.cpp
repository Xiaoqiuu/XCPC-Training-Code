#include <iostream>
#include <vector>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d%d", &n, &k);
        vector<int> v;
        while (n) {
            if (n % k)
                v.push_back(n % k);
            n /= k;
        }
        printf("%d\n", v.size());
    }
    return 0;
}
