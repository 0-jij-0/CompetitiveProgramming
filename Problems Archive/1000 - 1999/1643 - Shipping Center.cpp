#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
vector<int> b;

int main() {
	int n, m, q; cin >> n >> m >> q;
	v.resize(n); b.resize(m);
	for (auto& x : v) { cin >> x.first >> x.second; }
	for (auto& x : b) { cin >> x; }
	sort(v.begin(), v.end());

	while (q--) {
		int l, r; cin >> l >> r; l--; r--;
		int res = 0; vector<int> W(n), V(n), tb;
		for (int i = 0; i < n; i++) {
			W[i] = v[i].first; V[i] = v[i].second;
		}
		for (int i = 0; i < m; i++) {
			if (i == l) { i = r; continue; }
			tb.push_back(b[i]);
		}
		sort(tb.begin(), tb.end());

		for (auto& x : tb) {
			int idx = upper_bound(W.begin(), W.end(), x) - W.begin();
			if (idx == 0) { continue; }
			auto ma = max_element(V.begin(), V.begin() + idx);
			res += *ma; *ma = 0;
		}
		cout << res << '\n';
	}

	cin.ignore(2); return 0;
}