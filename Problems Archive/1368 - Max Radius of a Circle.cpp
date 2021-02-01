#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
typedef int ll;
typedef double ld;
const ld EPS = 1e-10;
const ld INF = 1e10;

vector<pair<ll, ll>> v;
vector<ld> d;

inline ld dist2(pair<ll, ll> &p1, pair<ll, ll> &p2) {
	ld dx = p1.first - p2.first;
	ld dy = p1.second - p2.second;
	return dx * dx + dy * dy;
}

inline ld slope(pair<ll, ll> &p1, pair<ll, ll> &p2) {
	ld dx = p1.first - p2.first;
	ld dy = p1.second - p2.second;
	if (abs(dx) <= EPS) { return INF; }
	return (dy + 0.0) / (dx + 0.0);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("circle.in", "r", stdin);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n); d.resize(n + 1);
		for (auto &x : v) { cin >> x.first >> x.second; }
		ll xc, yc; cin >> xc >> yc; v.push_back(v.front());
		pair<ll, ll> C(xc, yc); ld res = 1e15;
		for (int i = 0; i <= n; i++) d[i] = dist2(C, v[i]);

		for (int i = 0; i < n; i++) {
			ld &AC2 = d[i];	ld &BC2 = d[i + 1];
			ld AB2 = dist2(v[i], v[i + 1]);

			if (AC2 <= EPS) { res = 0.0; break; }
			if (BC2 <= EPS) { res = 0.0; break; }
			if (AB2 <= EPS) { res = min(res, sqrt(AC2)); continue; }

			ld A = (-BC2 + AB2 + AC2);
			ld B = (-AC2 + AB2 + BC2);

			if (A <= EPS) { res = min(res, sqrt(AC2)); continue; }
			if (B <= EPS) { res = min(res, sqrt(BC2)); continue; }

			ld a = slope(v[i], v[i + 1]), b = v[i].second - a * v[i].first;
			ld d = (a >= (INF - EPS)) ? abs(v[i].first - xc) : abs(yc - a * xc - b) / sqrt(a * a + 1.0);
			res = min(res, d);
		}
		cout << fixed << setprecision(10) << res << '\n';
	}
	return 0;
}