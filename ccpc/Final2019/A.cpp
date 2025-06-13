#include <iostream>
#include <vector>
using namespace std;
#define pb push_back
vector<string> month = {"0", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sept", "Oct", "Nov", "Dec"};
vector<string> day = {"0", "1st", "2nd", "3rd", "4th", "5th", "6th", "7th"\
                      "8th", "9th", "10th", "11th", "12th", "13th", "14th", "15th", "16th", "17th", "18th", "19th", "20th", "21th"\
                      "22th", "23th", "24th", "25th", "26th", "27th", "28th", "29th", "30th", "31th"};

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> db;
    for (int i = 1; i <= n; ++ i) {
        string m, d; cin >> m >> d;
        int j = -1;
        for (j = 1; j <= 12; ++ i) {
            if (month[j] == m) break;
        }
        d.erase(d.end()-2, d.end());
        int k = stoi(d);
        db.pb({j, k});
    }
    string need_month, need_day; cin >> need_month >> need_day;
    int target_m , target_d;
    for (target_m = 1; target_m <= 12; ++ i) {
            if (month[target_m] == need_month) break;
        }
    target_d.erase(target_d.end()-2, target_d.end());
}

signed main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int _; cin >> _;
    for (int i = 1; i <= _; ++ i) {
        cout << "Case #" << i << ": ";
        solve();
    }

}