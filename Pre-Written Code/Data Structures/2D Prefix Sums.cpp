#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin.ignore(2); return 0;
}