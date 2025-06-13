#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define vc vector<char>
#define ll long long
#define akitama return 0

//vc a, b, c, d, e, f, g;
string a, b, c, d, e, f, g;
string num[11][8];
ll len = -1;

inline void init_num() {
    num[0][1] = "xxxxx";
    num[0][2] = "x...x";
    num[0][3] = "x...x";
    num[0][4] = "x...x";
    num[0][5] = "x...x";
    num[0][6] = "x...x";
    num[0][7] = "xxxxx";

    num[1][1] = "....x";
    num[1][2] = "....x";
    num[1][3] = "....x";
    num[1][4] = "....x";
    num[1][5] = "....x";
    num[1][6] = "....x";
    num[1][7] = "....x";

    num[2][1] = "xxxxx";
    num[2][2] = "....x";
    num[2][3] = "....x";
    num[2][4] = "xxxxx";
    num[2][5] = "x....";
    num[2][6] = "x....";
    num[2][7] = "xxxxx";

    num[3][1] = "xxxxx";
    num[3][2] = "....x";
    num[3][3] = "....x";
    num[3][4] = "xxxxx";
    num[3][5] = "....x";
    num[3][6] = "....x";
    num[3][7] = "xxxxx";

    num[4][1] = "x...x";
    num[4][2] = "x...x";
    num[4][3] = "x...x";
    num[4][4] = "xxxxx";
    num[4][5] = "....x";
    num[4][6] = "....x";
    num[4][7] = "....x";

    num[5][1] = "xxxxx";
    num[5][2] = "x....";
    num[5][3] = "x....";
    num[5][4] = "xxxxx";
    num[5][5] = "....x";
    num[5][6] = "....x";
    num[5][7] = "xxxxx";

    num[6][1] = "xxxxx";
    num[6][2] = "x....";
    num[6][3] = "x....";
    num[6][4] = "xxxxx";
    num[6][5] = "x...x";
    num[6][6] = "x...x";
    num[6][7] = "xxxxx";

    num[7][1] = "xxxxx";
    num[7][2] = "....x";
    num[7][3] = "....x";
    num[7][4] = "....x";
    num[7][5] = "....x";
    num[7][6] = "....x";
    num[7][7] = "....x";

    num[8][1] = "xxxxx";
    num[8][2] = "x...x";
    num[8][3] = "x...x";
    num[8][4] = "xxxxx";
    num[8][5] = "x...x";
    num[8][6] = "x...x";
    num[8][7] = "xxxxx";

    num[9][1] = "xxxxx";
    num[9][2] = "x...x";
    num[9][3] = "x...x";
    num[9][4] = "xxxxx";
    num[9][5] = "....x";
    num[9][6] = "....x";
    num[9][7] = "xxxxx";

    num[10][1] = ".....";
    num[10][2] = "..x..";
    num[10][3] = "..x..";
    num[10][4] = ".xxx.";
    num[10][5] = "..x..";
    num[10][6] = "..x..";
    num[10][7] = ".....";

}

int get_num(string s[7], int pos) {
    for (int k = 0; k <= 10; ++k) {
        bool match = true;
        for (int i = 1; i <= 7; ++i) {
            if (s[i].substr(pos, 5) != num[k][i]) {
                match = false;
                break;
            }
        }
        if (match) return k;
    }
    return -1;
}

void solve() {
    string s[8];
    s[1] = a;
    s[2] = b;
    s[3] = c;
    s[4] = d;
    s[5] = e;
    s[6] = f;
    s[7] = g;

    ll A = 0, B = 0;
    int i = 0;
    while (i < len) {
        int num_val = get_num(s, i);
        if (num_val == 10) {
            i += 6;
            break;
        }
        A = A * 10 + num_val;
        i += 5;
    }
    while (i < len) {
        int num_val = get_num(s, i);
        B = B * 10 + num_val;
        i += 5;
    }

    ll result = A + B;
    string res_str = to_string(result);

    for (int row = 1; row <= 7; ++row) {
        string line;
        for (char ch : res_str) {
            int idx = ch - '0';
            line += num[idx][row] + ".";
        }
        line.pop_back();
        cout << line << endl;
    }
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    init_num();
    cin >> a >> b >> c >> d >> e >> f >> g;
    len = a.length();
    solve();
    akitama;
}