#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, m; cin >> n >> m; v.resize(n);

		int ones = 0;
		for (auto& x : v) {
			cin >> x;
			ones += count(x.begin(), x.end(), '1');
		}

		bool ok = false;
		for(int i = 0; i < n && !ok; i++)
			for(int j = 0; j < m - 1; j++)
				if (v[i][j] == v[i][j + 1] && v[i][j] == '0') { ok = true; break; }

		if (ok) { cout << ones << '\n'; continue; }

		for (int i = 0; i < n - 1 && !ok; i++)
			for (int j = 0; j < m; j++)
				if (v[i][j] == v[i + 1][j] && v[i][j] == '0') { ok = true; break; }

		if (ok) { cout << ones << '\n'; continue; }

		for (int i = 0; i < n - 1 && !ok; i++)
			for (int j = 0; j < m - 1; j++)
				if (v[i][j] == v[i + 1][j + 1] && v[i][j] == '0') { ok = true; break; }

		if (ok) { cout << ones << '\n'; continue; }

		for (int i = 0; i < n - 1 && !ok; i++)
			for (int j = 1; j < m; j++)
				if (v[i][j] == v[i + 1][j - 1] && v[i][j] == '0') { ok = true; break; }

		if (ok) { cout << ones << '\n'; continue; }

		cout << ones - 1 - (ones == n * m) << '\n';
	}
}