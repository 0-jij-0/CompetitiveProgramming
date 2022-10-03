#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> res;
vector<vector<int>> v(200001);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x; v[x].push_back(i);
	}

	int i = 200000, S = 0; while(i) {
		if (v[i].empty()) { i--; continue; }
		int a = v[i].back(), deg = i; v[i].pop_back();

		vector<pair<int, int>> N; int j = i;
		while (j && deg) {
			if (v[j].empty()) { j--; continue; }
			int b = v[j].back(); v[j].pop_back(); deg--; ++S;
			N.emplace_back(j - 1, b); res.emplace_back(a + 1, b + 1);
		}

		if (deg) { cout << "IMPOSSIBLE\n"; return 0; }
		for (auto&[x, y] : N) if(x) v[x].emplace_back(y);
	}

	cout << S << '\n'; for (auto& [x, y] : res)
		cout << x << ' ' << y << '\n';
}