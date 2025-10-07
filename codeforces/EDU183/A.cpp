#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::vector;
using std::sort;
using std::string;

using ll = long long int;

#define akitama return 0
#define vi vector<int>
#define vll vector<ll>

signed main() {
	int _; cin >> _;
	while (_--) {
		int n; cin >> n;
		cout << (3 - n % 3) % 3 << std::endl;
	}
}