#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;

int main() {
	freopen("dal.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		vector<int> compX, compY; for (auto& x : v) {
			cin >> x.first >> x.second;
			compX.push_back(x.first);
			compY.push_back(x.second);
		} 
		sort(compX.begin(), compX.end());
		sort(compY.begin(), compY.end());
		compX.erase(unique(compX.begin(), compX.end()), compX.end());
		compY.erase(unique(compY.begin(), compY.end()), compY.end());

		vector<vector<bool>> G(compX.size(), vector<bool>(compY.size(), 0));
		for (auto& x : v) {
			x.first = lower_bound(compX.begin(), compX.end(), x.first) - compX.begin();
			x.second = lower_bound(compY.begin(), compY.end(), x.second) - compY.begin();
			G[x.first][x.second] = 1;
		} sort(v.begin(), v.end());

		int res = 0; for(int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++) {
				if (v[i].first == v[j].first) { continue; }
				if (v[i].second >= v[j].second) { continue; }
				if (!G[v[j].first][v[i].second]) { continue; }
				int dx = compX[v[j].first] - compX[v[i].first];
				int dy = compY[v[j].second] - compY[v[i].second];
				res += dx == dy;
			}
		cout << res << '\n';
	}

	cin.ignore(2); return 0;
}