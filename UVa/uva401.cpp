#include <iostream>
#include <string>
#include <cctype>
using namespace std;

const char* table = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";

void print(string s, int a) {
	switch(a) {
	case 1: cout << s << " -- is not a palindrome.\n"; break;
	case 2: cout << s << " -- is a regular palindrome.\n"; break;
	case 3: cout << s << " -- is a mirrored string.\n"; break;
	case 4: cout << s << " -- is a mirrored palindrome.\n"; break;
	}
	cout << endl;
}

char check(char ch) {
	if (isalpha(ch)) {
		return table[ch - 'A'];
	} else {
		return table[ch - '0' + 25];
	}
}

signed main() {
	string s;
	while (cin >> s) {
		int len = s.size();
		bool f1 = 1, f2 = 1; // f1 aba f2 3ba
		for (int i = 0; i < (len + 1) / 2; ++ i) {
			int l = i, r = len - 1 - i;
			if (s[l] != s[r]) f1 = 0;
			if (check(s[l]) != s[r]) f2 = 0;
		}
		
		if (f1 && !f2) print(s, 2);
		else if (!f1 && f2) print(s, 3);
		else if (!f1 && !f2) print(s, 1);
		else print(s, 4);
	}
}