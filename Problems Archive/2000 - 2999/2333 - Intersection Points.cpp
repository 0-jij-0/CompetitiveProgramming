#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
typedef long long ll;
const int MIN = -1000000, MAX = 1000000;

struct FT {
	int n; vector<ll> vals; FT() {}
	FT(const int _n) : n(_n), vals(n + 1, 0) {}

	void update(int i, const ll x) {
		for (++i; i <= n; i += i & -i)	vals[i] += x;
	}
	ll query(int i) const {
		ll sum = 0;
		for (++i; i; i -= i & -i) sum += vals[i];
		return sum;
	}
	ll query(int i, int j) const { return query(j) - query(i - 1); }
};

vector<int> start[MAX - MIN + 1], finish[MAX - MIN + 1];
vector<tuple<int, int, int>> vert;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n; int m = 0;
	for (int i = 0; i < n; i++) {
		int x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
		x1 -= MIN; x2 -= MIN; y1 -= MIN; y2 -= MIN;
		if (x1 == x2) { ++m; vert.emplace_back(x1, y1, y2); continue; }
		start[x1].push_back(y1); finish[x2 + 1].push_back(y1);
	}
	sort(vert.begin(), vert.end());

	FT ft(MAX - MIN + 1); ll res = 0;
	for (int i = 0, curX = 0; i < m; i++) {
		int X, yL, yR; tie(X, yL, yR) = vert[i];
		for (; curX <= X; ++curX) {
			for (auto& y : start[curX]) ft.update(y, 1);
			for (auto& y : finish[curX]) ft.update(y, -1);
		}
		res += ft.query(yL, yR);
	}

	cout << res << '\n';
}