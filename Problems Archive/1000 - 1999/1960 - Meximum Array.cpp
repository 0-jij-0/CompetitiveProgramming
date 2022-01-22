#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.clear(); v.resize(n + 1);
		for (int i = 0; i < n; i++) {
			int x; cin >> x; v[x].push_back(i);
		}

		int rem = n, prev = 0, cur = 0;
		vector<int> idx(n + 2, 0);

		vector<int> res; while (idx[0] != (int) v[0].size()) {
			int mex = 0; while (true) {
				while (idx[mex] != v[mex].size() && v[mex][idx[mex]] < prev) { idx[mex]++; }
				if (idx[mex] == (int)v[mex].size()) { break; }
				cur = max(cur, v[mex][idx[mex]] + 1); idx[mex++]++;
			}
			res.push_back(mex); prev = cur;
			while (idx[0] != v[0].size() && v[0][idx[0]] < prev) { idx[0]++; }
		}
		while (cur != n) { res.push_back(0); cur++; }
		cout << res.size() << '\n';
		for (auto& x : res) cout << x << ' '; cout << '\n';
	}
	cin.ignore(2); return 0;
}