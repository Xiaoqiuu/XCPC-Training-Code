#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool isPrime(int num) {
    if (num < 2) return false;
    for (int j = 2; j * j <= num; j++) {
        if (num % j == 0) return false; 
    }
    return true;
}

int main() {
    int n, m, r, k;
    cin >> n >> m >> r;
    cin >> k;

    vector<int> vec; 

    for (int i = 1; i <= n; i++) {
        if (isPrime(i) && (i % m == r)) {
            vec.push_back(i); 
        }
    }

    sort(vec.rbegin(), vec.rend());

    if (k > vec.size()) {
        cout << -1 << endl;
    } else {
        cout << vec[k - 1] << endl; 
    }

    return 0;
}

