// WA 2

#include <bits/stdc++.h>
using namespace std;
#define akitama return 0
#define ll long long int
#define GAY 1

// Jiangly's template

/**   线段树（SegmentTree+Info+Merge 初始赋值+单点修改+区间合并）
 *    2022-04-23: https://codeforces.com/contest/1672/submission/154766851
 **/
template<class Info,
class Merge = std::plus<Info>>
struct SegmentTree {
	const int n;
	const Merge merge;
	std::vector<Info> info;
	SegmentTree(int n) : n(n), merge(Merge()), info(4 << std::__lg(n)) {}
	SegmentTree(std::vector<Info> init) : SegmentTree(init.size()) {
		std::function<void(int, int, int)> build = [&](int p, int l, int r) {
			if (r - l == 1) {
				info[p] = init[l];
				return;
			}
			int m = (l + r) / 2;
			build(2 * p, l, m);
			build(2 * p + 1, m, r);
			pull(p);
		};
		build(1, 0, n);
	}
	void pull(int p) {
		info[p] = merge(info[2 * p], info[2 * p + 1]);
	}
	void modify(int p, int l, int r, int x, const Info &v) {
		if (r - l == 1) {
			info[p] = v;
			return;
		}
		int m = (l + r) / 2;
		if (x < m) {
			modify(2 * p, l, m, x, v);
		} else {
			modify(2 * p + 1, m, r, x, v);
		}
		pull(p);
	}
	void modify(int p, const Info &v) {
		modify(1, 0, n, p, v);
	}
	Info rangeQuery(int p, int l, int r, int x, int y) {
		if (l >= y || r <= x) {
			return Info();
		}
		if (l >= x && r <= y) {
			return info[p];
		}
		int m = (l + r) / 2;
		return merge(rangeQuery(2 * p, l, m, x, y), rangeQuery(2 * p + 1, m, r, x, y));
	}
	Info rangeQuery(int l, int r) {
		return rangeQuery(1, 0, n, l, r);
	}
};

struct Info {
	ll val; int pos;
	Info(ll v = -1, int p = -1) : val(v), pos(p) {}
};
Info operator+(const Info &L, const Info &R) {
	if (L.val >= R.val) return L;
	return R;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int _; cin >> _;
	while (_--) {
		int n, m; cin >> n >> m;
		vector<ll> a(n);
		for (int i = 0; i < n; ++ i) cin >> a[i];
		vector<ll> b(m), c(m);
		for (int i = 0; i < m; ++ i) cin >> b[i];
		for (int i = 0; i < m; ++ i) cin >> c[i];

		vector<ll> uniq = b;
		sort(uniq.begin(), uniq.end()); uniq.erase(unique(uniq.begin(), uniq.end()), uniq.end());
		int K = (int)uniq.size();

		vector<priority_queue<ll>> buckets(K);
		for (int i = 0; i < m; ++i) {
			int id = int(lower_bound(uniq.begin(), uniq.end(), b[i]) - uniq.begin());
			buckets[id].push(c[i]);
		}
		
		vector<Info> base(K);
		for (int i = 0; i < K; ++i) {
			if (!buckets[i].empty()) base[i] = Info(buckets[i].top(), i);
			else base[i] = Info(-1, i);
		}
		SegmentTree<Info> seg(base);
		
		sort(a.begin(), a.end());
		ll ans = 0;
		
		for (ll s : a) {
			while (GAY) {
				int idx = int(upper_bound(uniq.begin(), uniq.end(), s) - uniq.begin()) - 1;
				if (idx < 0) break;
				
				Info best = seg.rangeQuery(0, idx + 1); 
				if (best.val < 0) break; 
				
				ll gay = best.val;
				int pos = best.pos;
				
				
				buckets[pos].pop();
				ll nxt = buckets[pos].empty() ? -1 : buckets[pos].top();
				seg.modify(pos, Info(nxt, pos));
				
				++ans;
				if (gay > s) s = gay; 
			}
		}
		
		cout << ans << '\n';
	}
	akitama;
}
