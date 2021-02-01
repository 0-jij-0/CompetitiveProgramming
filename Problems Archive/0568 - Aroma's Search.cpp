#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
vector<pair<ll, ll>> v;

ll x, y, ax, ay, bx, by;
ll xs, ys, t;
const ll INF = 1ll << 55;

ll dist(ll x1, ll y1, ll x2, ll y2) {
	ll dx = abs(x1 - x2), dy = abs(y1 - y2);
	return (dx + dy >= 0) ? dx + dy : INF + 1;
}

void next(ll &x, ll &y) {
	x = ax * x + bx; y = ay * y + by;
}

int main() {
	cin >> x >> y >> ax >> ay >> bx >> by;
	cin >> xs >> ys >> t;
	while (dist(x, y, xs, ys) > t && x < INF && y < INF) { next(x, y); }
	while (dist(x, y, xs, ys) <= t) {
		v.push_back({ x, y });
		next(x, y);
	}
	int n = (int)v.size(), res = 0;
	for(int l = 0; l < n; l++)
		for (int r = l; r < n; r++) {
			ll d = dist(v[l].first, v[l].second, v[r].first, v[r].second);
			ll d1 = dist(xs, ys, v[r].first, v[r].second);
			ll d2 = dist(xs, ys, v[l].first, v[l].second);
			if (d1 + d <= t || d2 + d <= t)
				res = max(res, r - l + 1);
		}
	cout << res << endl;
	cin.ignore(2); return 0;
}