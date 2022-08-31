#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct PrefSum2D {
	vector<vector<ll>> pref; int n; PrefSum2D() {}
	PrefSum2D(vector<vector<ll>>& _v) : n(_v.size()), pref(_v) {
		for (int j = 1; j < n; j++) { pref[0][j] += pref[0][j - 1]; }
		for (int i = 1; i < n; i++) { pref[i][0] += pref[i - 1][0]; }
		for (int i = 1; i < n; i++)	for (int j = 1; j < n; j++)
			pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
	}
	ll query(int hs, int hb, int ws, int wb) {
		ll res = pref[hb][wb];
		if (hs) { res -= pref[hs - 1][wb]; }
		if (ws) { res -= pref[hb][ws - 1]; }
		if (hs && ws) { res += pref[hs - 1][ws - 1]; }
		return res;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, q; cin >> n >> q;
		vector<vector<ll>> v(1001, vector<ll>(1001, 0));
		for (int i = 0; i < n; i++) {
			int h, w; cin >> h >> w;
			v[h][w] += h * w;
		}

		PrefSum2D ps(v); while (q--) {
			int hs, ws, hb, wb; cin >> hs >> ws >> hb >> wb;
			cout << ps.query(hs + 1, hb - 1, ws + 1, wb - 1) << '\n';
		}
	}
}