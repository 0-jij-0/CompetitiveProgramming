#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;

int main() {
	int n, m; cin >> n >> m; v.resize(n);
	for (int i = 0; i < n; i++) {
		int x; cin >> x; v[x].push_back(i);
	}

	int res = n;
	for (int i = 0; i < n && res == n; i++) {
		if (v[i].empty()) { res = i; break; }
		if (v[i].front() >= m) { res = i; break; }
		if (n - v[i].back() > m) { res = i; break; }
		for(int j = 1; j < (int)v[i].size(); j++)
			if (v[i][j] - v[i][j - 1] > m) { res = i; break; }
	}

	cout << res << '\n';
	cin.ignore(2); return 0;
}