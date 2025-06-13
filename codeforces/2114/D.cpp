#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<pair<ll,ll>> a(n);
        for(int i=0;i<n;i++) cin >> a[i].first >> a[i].second;
        if(n==1){
            cout << 1 << "\n";
            continue;
        }
        ll xmin=LLONG_MAX, xmax=LLONG_MIN;
        ll ymin=LLONG_MAX, ymax=LLONG_MIN;
        for(auto &p:a){
            xmin = min(xmin, p.first);
            xmax = max(xmax, p.first);
            ymin = min(ymin, p.second);
            ymax = max(ymax, p.second);
        }
        // 次极值 & 计数
        ll xmn2=LLONG_MAX, xmx2=LLONG_MIN;
        ll ymn2=LLONG_MAX, ymx2=LLONG_MIN;
        int cxmn=0, cxmx=0, cymn=0, cymx=0;
        for(auto &p:a){
            ll x=p.first, y=p.second;
            if(x==xmin) cxmn++; else xmn2 = min(xmn2, x);
            if(x==xmax) cxmx++; else xmx2 = max(xmx2, x);
            if(y==ymin) cymn++; else ymn2 = min(ymn2, y);
            if(y==ymax) cymx++; else ymx2 = max(ymx2, y);
        }
        if(xmn2==LLONG_MAX) xmn2=xmin;
        if(xmx2==LLONG_MIN) xmx2=xmax;
        if(ymn2==LLONG_MAX) ymn2=ymin;
        if(ymx2==LLONG_MIN) ymx2=ymax;

        // 不搬怪
        ll w0 = xmax - xmin + 1;
        ll h0 = ymax - ymin + 1;
        ll ans = w0 * h0;

        // 枚举搬走每只怪
        ll m = n - 1;
        for(auto &p:a){
            ll x=p.first, y=p.second;
            ll x0 = (x==xmin && cxmn==1 ? xmn2 : xmin);
            ll x1 = (x==xmax && cxmx==1 ? xmx2 : xmax);
            ll y0 = (y==ymin && cymn==1 ? ymn2 : ymin);
            ll y1 = (y==ymax && cymx==1 ? ymx2 : ymax);
            ll w = x1 - x0 + 1;
            ll h = y1 - y0 + 1;
            ll cost;
            if(w*h > m) cost = w*h;
            else cost = min((w+1)*h, w*(h+1));
            ans = min(ans, cost);
        }
        cout << ans << "\n";
    }
    return 0;
}
