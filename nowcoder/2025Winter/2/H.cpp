#include <bits/stdc++.h>
//#include <iostream>
using namespace std;

#define akitama return 0
#define ll long long
#define vi vector<int>

struct Pt {
    int x, y;
};

bool col(const Pt& p1, const Pt& p2, const Pt& p3){
    ll ar = (ll)p1.x*(p2.y - p3.y) + (ll)p2.x*(p3.y - p1.y) + (ll)p3.x*(p1.y - p2.y);
    return ar == 0;
}

double dist(const Pt& p1, const Pt& p2){
    double dx = (double)(p1.x - p2.x);
    double dy = (double)(p1.y - p2.y);
    return sqrt(dx*dx + dy*dy);
}

double cr(const Pt& p1, const Pt& p2, const Pt& p3){
    double a = dist(p1, p2);
    double b = dist(p1, p3);
    double c = dist(p2, p3);
    double ar = abs((ll)p1.x*(p2.y - p3.y) + (ll)p2.x*(p3.y - p1.y) + (ll)p3.x*(p1.y - p2.y)) / 2.0;
    if(ar == 0) return -1.0;
    return (a * b * c) / (4.0 * ar);
}

vector<Pt> gen(int a, int b, int c, int d){
    set<pair<int, int>> cand;
    cand.emplace(a, c);
    cand.emplace(a, d);
    cand.emplace(b, c);
    cand.emplace(b, d);
    int xs = a + b;
    int ys = c + d;
    int xf = xs / 2;
    int xc = (xs % 2 != 0) ? xf + 1 : xf;
    if(a <= xf && xf <= b){
        cand.emplace(xf, c);
        cand.emplace(xf, d);
    }
    if(a <= xc && xc != xf && xc <= b){
        cand.emplace(xc, c);
        cand.emplace(xc, d);
    }
    int yf = ys / 2;
    int yc = (ys % 2 != 0) ? yf + 1 : yf;
    if(c <= yf && yf <= d){
        cand.emplace(a, yf);
        cand.emplace(b, yf);
    }
    if(c <= yc && yc != yf && yc <= d){
        cand.emplace(a, yc);
        cand.emplace(b, yc);
    }
    vector<Pt> res;
    for(auto &[x, y] : cand){
        res.push_back(Pt{ x, y });
    }
    return res;
}

void solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<Pt> cand = gen(a, b, c, d);
    double maxR = -1.0;
    vector<Pt> best;
    int n = cand.size();
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            for(int k=j+1;k<n;k++) {
                Pt p1 = cand[i];
                Pt p2 = cand[j];
                Pt p3 = cand[k];
                if(col(p1, p2, p3)) continue;
                double R = cr(p1, p2, p3);
                if(R > maxR){
                    maxR = R;
                    best = {p1, p2, p3};
                }
            }
        }
    }
    for(auto &p : best){
        cout << p.x << " " << p.y << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    akitama;
}
