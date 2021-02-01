#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;
typedef long long ll;

struct FT {
	int n; vector<ll> vals; FT() {}
	FT(const int _n) : n(_n), vals(n + 1, 0) {}

	//Adds x
	void update(int i, const ll x) {
		for (++i; i <= n; i += i & -i)	vals[i] += x;
	}
	ll query(int i) const { // sum from 0 ... i
		assert(i >= -1 && i < n); ll sum = 0;
		for (++i; i; i -= i & -i) sum += vals[i];
		return sum;
	}
	ll query(int i, int j) const { return query(j) - query(i - 1); }
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int R = 1000000; ll ans = 0;
	vector<vector<int>> start(R + 2), end(R + 2);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int y, l, r; cin >> y >> l >> r;
		if (l == 0 && r == R) { ans++; }
		start[l].push_back(y);
		end[r + 1].push_back(y);
	}

	vector<pair<int, pair<int, int>>> vert;
	for (int i = 0; i < m; i++) {
		int x, l, r; cin >> x >> l >> r;
		vert.push_back({ x, {l, r} });
		if (l == 0 && r == R) { ans++; }
	}
	sort(vert.begin(), vert.end());

	FT ft(R + 2); int curX = 0;
	for (int i = 0; i < m; i++) {
		while (curX <= vert[i].first) {
			for (auto &y : start[curX]) { ft.update(y, 1); }
			for (auto &y : end[curX]) { ft.update(y, -1); }
			curX++;
		}
		ans += ft.query(vert[i].second.first, vert[i].second.second);
	}

	cout << ans + 1 << '\n';
}