#include <iostream>
#include <vector>
#include <algorithm>
#define akitama return 0
using namespace std;

int N;
vector<int> prime;
vector<bool> is_Prime;


void isPrime() {
    is_Prime.assign(N + 1, true);
    is_Prime[0] = is_Prime[1] = false;
    for (int i = 2; i * i <= N; ++ i) {
        if (is_Prime[i]) {
            for (int j = i * i; j <= N; ++ j) {
                is_Prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= N; ++ i) {
        if (is_Prime[i]) {
            prime.push_back(i);
        }
    }
}

signed main(void) {
    cin >> N;
    isPrime();
    cout << "---------" << endl;
    int num;
    cin >> num;
    // int len = prime.size();
    for (auto i : prime) {
        cout << i << " ";
    }

    // if (binary_search(prime.begin(), prime.end(), num)) {
    //     cout << num << " is a prime.\n"; 
    // } else cout << "NO PRIME FOUND.\n";
    akitama;
}