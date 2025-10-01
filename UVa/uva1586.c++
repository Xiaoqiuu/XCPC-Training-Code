#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cctype>
using namespace std;

const double C = 12.01;
const double H = 1.008;
const double O = 16.0;
const double N = 14.01;

double check(char c) {
	if (c == 'C') return C;
	else if (c == 'H') return H;
	else if (c == 'N') return N;
	else return O;
}

//vector<double> y = {12.01, 1.008, 16.00, 14.01};

signed main() {
	int _; cin >> _;
	while (_--) {
		string s; cin >> s;
		double ans = 0.0;
		string num = "";
//		int c = 0, h = 0, o = 0, n = 0;
		for (int i = 0; i < (int)s.size(); ++ i) {
			if (isdigit(s[i])) continue;
			else if (!isdigit(s[i + 1])) ans += check(s[i]);
			else {
				int x = 0;
				for (int j = i + 1; isdigit(s[j]); ++ j) {
					x = x * 10 + (s[j] - '0');
				} ans += check(s[i]) * x;
			}
		}
		
////		double res = 0.0;
//		string num = "";
//		char ch;
//		for (char c : s) {
//			if (c >= '0' && c <= '9') {
//				num += c;
//			} else {
//				if (!num.empty()) {
//					cout << ch << " * " << stoi(num) << endl;
//					if (ch == 'C') ans += C * (stoi(num) - 1); 
//					else if (ch == 'H') ans += H * (stoi(num) - 1); 
//					else if (ch == 'O') ans += O * (stoi(num) - 1); 
//					else if (ch == 'N') ans += N * (stoi(num) - 1); 
//				}
//				else {
//					if (c == 'C') ans += C; 
//					else if (c == 'H') ans += H; 
//					else if (c == 'O') ans += O; 
//					else if (c == 'N') ans += N; 
//				}
//				num = ""; 
//				ch = c;
//			}
//		}
		
		cout << fixed << setprecision(3);
		cout << ans << endl;
	}
}
