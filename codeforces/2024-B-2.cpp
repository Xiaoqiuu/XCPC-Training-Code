#include <iostream>
#include <unordered_map>
#define akitama return 0;
using ll = long long;
using namespace std;

int main() {
    int n;cin >> n;
    ll a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    unordered_map<ll, int> countMap;
    int currentPairs = 0;
    for (int i = 1; i <= n; i++) { 
        int currentCount = countMap[a[i]];
        currentPairs += currentCount;
        cout << currentPairs << " ";
        countMap[a[i]]++;
    }
    akitama;
}


//TLE
/*
#include <iostream>
#define akitama return 0;
using ll = long long;
using namespace std;

int main() {
    int n;cin >> n;
    ll a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        //数组a从1到i之间有多少对相同的数
        int cnt = 0;
        for (int j = 1; j < i; j++) {
            for (int k = j + 1; k <= i; k++) {
                if (a[j] == a[k]) {
                    cnt++;
                }
            }
        }

        cout << cnt << " ";
        }
    akitama;
}*/