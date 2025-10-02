#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
//#include <utility>

using namespace std;

#define pb push_back

int x = 0, y = 0;
string str = "";
bool f = 1;
void print() { 
	printf("This puzzle has no final configuration.\n");
	f = 0;
}

signed main() {
	
	int time = 0;
	while (getline(cin, str) && str != "Z") {
		if (time) cout << endl;
		printf("Puzzle #%d:\n",++time);
		vector<string> s;
		s.pb(str);
		for (int i = 1; i <= 4; ++ i) {
			getline(cin, str);
			s.pb(str);
		}
		
		string op;
		while (getline(cin, str)) {
			bool fc = 1;
			for (char c : str) if (c != '0') op.pb(c); else fc = 0;
			if (!fc) break;
		}
		
		for (int i = 0; i < 5; ++ i) {
			for (int j = 0; j < 5; ++ j) {
				if(s[i][j] == ' ') {
					x = i, y = j;
					break;
				}
			}
		}
		f = 1;
		for (char c : op) {
//			printf("current kongge: %d, %d\n", x, y);
			
			if (c == 'A') {
				if (x > 0) {
					s[x][y] = s[x - 1][y];
					s[x - 1][y] = ' ';
					x--;
				} else {
					print();
					break;
				}
			} else if (c == 'B') {
				if (x < 4) {
					s[x][y] = s[x + 1][y];
					s[x + 1][y] = ' ';
					x++;
				} else {
					print();
					break;
				}
			} else if (c == 'L') {
				if (y > 0) {
					s[x][y] = s[x][y - 1];
					s[x][y - 1] = ' ';
					y--;
				} else {
					print();
					break;
				}
			} else if (c == 'R') {
				if (y < 4) {
					s[x][y] = s[x][y + 1];
					s[x][y + 1] = ' ';
					y++;
				} else {
					print();
					break;
				}
			}
//			printf("op : %c, now position(%d, %d)\n----------\n", c, x, y);
		}
		if (f) {
			for (int i = 0; i < 5; ++ i) {
				for (int j = 0; j < 5; ++ j) {
					cout << s[i][j] << (j == 4? '\n' : ' ');
				}
			}
			
		}
	}
}