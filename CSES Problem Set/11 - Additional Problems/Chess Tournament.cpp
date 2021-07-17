#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<pair<int, int>> res;
vector<vector<int>> v(200001);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); 

	int n, i = 0; cin >> n; while (n--) {
		int x; cin >> x; v[x].push_back(i++);
	}

	bool ok = true; for (int i = 200000; i > 0; i--) {
		if (v[i].empty()) { continue; }
		int curU = v[i].back(), deg = i; v[i].pop_back();
		vector<pair<int, int>> N; int j = i; i++;
		while (j && deg) {
			if (v[j].empty()) { j--; continue; }
			int curV = v[j].back(); v[j].pop_back();
			N.emplace_back(j - 1, curV); deg--;
			res.emplace_back(curU, curV);
		}
		if (deg) { ok = false; break; }
		for (auto &x : N)v[x.first].emplace_back(x.second);
	}

	if (!ok) { cout << "IMPOSSIBLE\n"; return 0; }
	cout << res.size() << '\n'; for (auto &x : res) 
		cout << x.first + 1 << ' ' << x.second + 1 << '\n';
	cin.ignore(2); return 0;
}