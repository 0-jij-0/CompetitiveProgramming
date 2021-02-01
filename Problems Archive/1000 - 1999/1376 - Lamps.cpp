#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

vector<string> v;
vector<vector<int>> row, col;

ll power(ll x, ll n) {
	ll res = 1;
	for (; n; n >>= 1, x = (x * x) % mod)
		if (n & 1) res = (res * x) % mod;
	return res;
}

int main() {
	int h, w; cin >> h >> w; v.resize(h);
	row.resize(h, vector<int>(w));
	col.resize(h, vector<int>(w));
	for (auto &x : v) { cin >> x; }

	int K = 0; for (int i = 0; i < h; i++) {
		K += count(v[i].begin(), v[i].end(), '.');
		int j = 0, k = 0; while (k != w) {
			if (v[i][j] == '#') { j++; k++; continue; }
			if (v[i][k] == '.') { k++; continue; }
			for (int x = j; x < k; x++)	row[i][x] = k - j;
			j = k = k + 1;
		}
		for (int x = j; x < k; x++)	row[i][x] = k - j;
	}

	for (int j = 0; j < w; j++) {
		int i = 0, k = 0; while (k != h) {
			if (v[i][j] == '#') { i++; k++; continue; }
			if (v[k][j] == '.') { k++; continue; }
			for (int x = i; x < k; x++) col[x][j] = k - i;
			i = k = k + 1;
		}
		for (int x = i; x < k; x++) col[x][j] = k - i;
	}

	ll all = power(2, K), res = 0;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)	if (v[i][j] == '.')
				res = (res + all - power(2, K - row[i][j] - col[i][j] + 1) + mod) % mod;
	cout << res << '\n'; cin.ignore(2); return 0;
}