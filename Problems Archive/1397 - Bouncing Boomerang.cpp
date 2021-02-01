#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

set<pair<int, int>> res;
vector<int> v, f[4];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i]; f[v[i]].push_back(i);
	}

	bool ok = true; int y = 1;
	if (!f[3].empty()) {
		int i = n - 1; for (; i > f[3].back(); i--) {
			if (v[i] == 2) { ok = false; break; }
			if (v[i] == 1) { break; }
		}
		if (!ok || i == f[3].back()) { cout << -1 << '\n'; return 0; }
		int j = i; while (j > f[3].back()) {
			if (v[j] == 2) { break; }
			j--;
		}
		if (j == f[3].back()) {
			for (int x = 0; x < (int)f[3].size() - 1; x++) {
				res.insert({ f[3][x] + 1, y }); 
				res.insert({ f[3][x + 1] + 1, y++ });
				v[f[3][x]] = 0;
			}
			res.insert({ f[3].back() + 1, y }); v[f[3].back()] = 0;
			res.insert({ i + 1, y++ }); res.insert({ i + 1, y++ });
			v[i] = 0;
		}
		else {
			for (int x = 0; x < (int)f[3].size() - 1; x++) {
				res.insert({ f[3][x] + 1, y }); 
				res.insert({ f[3][x + 1] + 1, y++ });
				v[f[3][x]] = 0;
			}
			res.insert({ f[3].back() + 1, y }); v[f[3].back()] = 0;
			res.insert({ j + 1, y++ }); res.insert({ j + 1, y });
			res.insert({ i + 1, y++ }); v[i] = v[j] = 0;
		}
	}
	int i = 0;
	for (int x = 0; x < n; x++) {
		if (v[x] == 0) { continue; }
		if (v[x] == 1) { res.insert({ x + 1, y++ }); continue; }
		i = max(i, x + 1); while (i < n && v[i] != 1) { i++; }
		if (i == n) { ok = false; break; }
		res.insert({ x + 1, y }); res.insert({ i + 1, y++ });
		v[i] = 0; continue;
	}
	if (!ok || y > n + 1) { cout << -1 << '\n'; return 0; }
	cout << res.size() << '\n';
	for (auto &x : res) cout << x.second << ' ' << x.first << '\n';
	cin.ignore(2); return 0;
}