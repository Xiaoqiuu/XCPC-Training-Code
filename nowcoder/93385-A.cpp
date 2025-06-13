#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    string s;
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    char ch[101];cin >> ch;
    char tp = ch[1];ch[1] = ch[0];ch[0] = tp;
    for (auto i : ch) cout << ch[i];
    return 0;
}
