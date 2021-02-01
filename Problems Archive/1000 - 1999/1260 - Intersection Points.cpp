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

	int R = 2000000, add = 1000000; ll ans = 0;
	vector<vector<int>> start(R + 2), end(R + 2);
	vector<pair<int, pair<int, int>>> vert;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
		x1 += add; x2 += add; y1 += add; y2 += add;
		if (x1 == x2) { vert.push_back({ x1, { y1, y2 } }); continue; }
		start[x1].push_back(y1); end[x2 + 1].push_back(y1);
	}
	int m = (int)vert.size(); sort(vert.begin(), vert.end());

	FT ft(R + 2); int curX = 0;
	for (int i = 0; i < m; i++) {
		while (curX <= vert[i].first) {
			for (auto &y : start[curX]) { 
				ft.update(y, 1);
			}
			for (auto &y : end[curX]) { ft.update(y, -1); }
			curX++;
		}
		ans += ft.query(vert[i].second.first, vert[i].second.second);
	}

	cout << ans << '\n';
}