#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<pair<int, int>> v;
vector<int> res, vis;

vector<vector<int>> idx;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	v.resize(n); res.resize(m + 1); 
	idx.resize(m); vis.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
		idx[--v[i].first].push_back(i);
		idx[--v[i].second].push_back(i);
	}

	int L = 0, R = max_element(v.begin(), v.end())->first;
	bool ok = true; for (; L < m && ok; L++) {
		res[R - L]++; res[m - L]--;
		for (auto& x : idx[L]) {
			if (vis[x]) { ok = false; break; }
			vis[x] = true; R = max(R, v[x].second);
		}
	}

	res.pop_back();
	partial_sum(res.begin(), res.end(), res.begin());
	for (auto& x : res) cout << x << ' '; cout << '\n';
}