#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> wins;
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, q; cin >> n >> q; v.resize(n);
		for (auto& x : v) cin >> x;
		wins.clear(); wins.resize(n + 1);

		int curRound = 1, cur = v[0];
		int j = 1; while (cur != n) {
			if (cur > v[j]) { wins[cur].push_back(curRound++); j++; }
			else { wins[v[j]].push_back(curRound++); cur = v[j]; j++; }
		}

		while (q--) {
			int i, k; cin >> i >> k;
			if (v[--i] != n)
				cout << upper_bound(wins[v[i]].begin(), wins[v[i]].end(), k) - wins[v[i]].begin() << '\n';
			else cout << upper_bound(wins[n].begin(), wins[n].end(), k) - wins[n].begin() + max(0, k - curRound + 1) << '\n';
		}
	}
}