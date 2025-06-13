#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define akitama return 0
#define pb push_back
#define mp make_pair
const int MOD = 998244353;
const int N = 100005;
struct Tab { int a, b, d, u; };
struct Off { int c, x, y, id, u; };
struct CMP {
    bool operator()(const Off &p, const Off &q) {
        if(p.c != q.c) return p.c > q.c;
        if(p.x != q.x) return p.x > q.x;
        return p.y > q.y;
    }
};
Off mkOff(const Tab &t, int u, int id) {
    Off o; o.id = id; o.u = u;
    int bas = 3 * t.d;
    if(u == 0) { o.c = bas + 1; o.x = 3 * t.a + 1; o.y = 3 * t.b + 1; }
    else if(u == 1) { o.c = bas + 2; o.x = 3 * t.a + 1; o.y = 3 * t.b + 2; }
    else if(u == 2) { o.c = bas + 2; o.x = 3 * t.a + 2; o.y = 3 * t.b + 1; }
    else { o.c = bas + 5; o.x = 3 * t.a + 2; o.y = 3 * t.b + 2; }
    return o;
}
void solve(){
    int n; cin >> n;
    vi t(n);
    for(int i = 0; i < n; i++) cin >> t[i];
    static vector<Tab> v;
    if(v.empty()){
        int D = 317;
        for(int i = 0; i <= D; i++){
            for(int j = 0; j <= D - i; j++){
                Tab tt; tt.a = i; tt.b = j; tt.d = i + j; tt.u = 0;
                v.pb(tt);
            }
        }
        sort(v.begin(), v.end(), [](const Tab &p, const Tab &q){
            if(p.d != q.d) return p.d < q.d;
            if(p.a != q.a) return p.a < q.a;
            return p.b < q.b;
        });
    }
    int p = 0;
    priority_queue<Off, vector<Off>, CMP> pq;
    vector<pii> an(n);
    vi use;
    for(int i = 0; i < n; i++){
        Off cur;
        if(t[i] == 0){
            cur = mkOff(v[p], 0, p);
            p++;
        } else {
            bool av1 = false, av2 = false;
            Off c1, c2;
            if(p < v.size()){
                c1 = mkOff(v[p], 0, p);
                av1 = true;
            }
            while(!pq.empty()){
                c2 = pq.top(); pq.pop();
                if(v[c2.id].u == c2.u){ av2 = true; break; }
            }
            if(av1 && av2){
                if(c1.c < c2.c) { cur = c1; p++; }
                else if(c1.c > c2.c) { cur = c2; }
                else if(c1.x < c2.x) { cur = c1; p++; }
                else if(c1.x > c2.x) { cur = c2; }
                else { if(c1.y <= c2.y) { cur = c1; p++; } else { cur = c2; } }
            } else if(av1){
                cur = c1; p++;
            } else {
                cur = c2;
            }
        }
        an[i] = mp(cur.x, cur.y);
        int id = cur.id;
        v[id].u++;
        if(v[id].u == 1) use.pb(id);
        if(v[id].u < 4){
            Off no = mkOff(v[id], v[id].u, id);
            pq.push(no);
        }
    }
    for(auto &pr : an) cout << pr.first << " " << pr.second << "\n";
    for(auto id : use) v[id].u = 0;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc; cin >> tc;
    while(tc--) solve();
    akitama;
}
