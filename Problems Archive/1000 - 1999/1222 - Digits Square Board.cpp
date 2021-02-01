#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef int ll;

struct PrefSum2D {
	vector<vector<ll>> v; int n; PrefSum2D() {}
	PrefSum2D(vector<vector<ll>> &_v) : n(_v.size()), v(_v) {
		for (int j = 1; j < n; j++) { v[0][j] += v[0][j - 1]; }
		for (int i = 1; i < n; i++) { v[i][0] += v[i - 1][0]; }
		for (int i = 1; i < n; i++)	for (int j = 1; j < n; j++)
				v[i][j] += v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
	}
	ll query(int x1, int y1, int x2, int y2) {
		ll res = v[x2][y2];
		if (x1) { res -= v[x1 - 1][y2]; }
		if (y1) { res -= v[x2][y1 - 1]; }
		if (x1 && y1) { res += v[x1 - 1][y1 - 1]; }
		return res;
	}
};

int mex[31][31][31][31]; int n;

int findMex(int x1, int y1, int x2, int y2, PrefSum2D &ps) {
	if (x1 == x2 && y1 == y2) { return 0; }
	if (ps.query(x1, y1, x2, y2) == 0) { return 0; }
	if (mex[x1][y1][x2][y2] != -1) { return mex[x1][y1][x2][y2]; }

	vector<int> res(n << 1 | 1, 0);
	for (int x = x1 + 1; x <= x2; x++)
		res[findMex(x1, y1, x - 1, y2, ps) ^ findMex(x, y1, x2, y2, ps)] = 1;
	for (int y = y1 + 1; y <= y2; y++)
		res[findMex(x1, y1, x2, y - 1, ps) ^ findMex(x1, y, x2, y2, ps)] = 1;

	return mex[x1][y1][x2][y2] = find(res.begin(), res.end(), 0) - res.begin();
}

set<int> primes = { 2, 3, 5, 7 };
vector<vector<int>> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		cin >> n; v.clear(); v.resize(n, vector<int>(n));
		for (auto &x : v) for (auto &y : x) { cin >> y; y = !primes.count(y); }
		PrefSum2D ps(v); fill(mex[0][0][0], mex[0][0][0] + 31 * 31 * 31 * 31, -1);
		cout << (findMex(0, 0, n - 1, n - 1, ps) ? "First" : "Second") << '\n';
	}
	cin.ignore(2); return 0;
}