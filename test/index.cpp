#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<int> v;
    int n, t;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &t);
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    for (int x : v)
        printf("%d ", x);
    return 0;
}
