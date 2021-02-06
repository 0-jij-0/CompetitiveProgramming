#include <iostream>
#include <vector>
using namespace std;

vector<int> a, b, c, res;
vector<vector<int>> freq1, freq2;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, m; cin >> n >> m; a.resize(n);
		b.resize(n); c.resize(m); res.resize(m);
		freq1.clear(); freq1.resize(n + 1);
		freq2.clear(); freq2.resize(n);
		for (auto& x : a) { cin >> x; --x; }
		for (auto& x : b) { cin >> x; --x; }
		for (auto& x : c) { cin >> x; --x; }

		for (int i = 0; i < n; i++) {
			if (a[i] != b[i]) freq1[b[i]].push_back(i);
			freq2[b[i]].push_back(i);
		}

		bool ok = true;
		for (int i = m - 1; i >= 0; i--) {
			if (freq1[c[i]].empty() && freq1[n].empty()) {
				if (freq2[c[i]].empty()) { ok = false; break; }
				res[i] = freq2[c[i]].back();
				freq1[n].push_back(res[i]);
				continue;
			}
			if (freq1[c[i]].empty()) { res[i] = freq1[n].back(); continue; }
			res[i] = freq1[c[i]].back(); freq1[n].push_back(res[i]); freq1[c[i]].pop_back();
		}

		for (int i = 0; i < n; i++) ok = ok && freq1[i].empty();
		
		if (!ok) { cout << "NO" << '\n'; continue; }
		cout << "YES" << '\n';
		for (auto& x : res) cout << x + 1 << ' '; cout << '\n';
	}

	cin.ignore(2); return 0;
}