#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

vector<string> G;

void simulateFallDown(string &s) {
	int l = 0, r = 0, n = (int)s.size();
	while (l != n) {
		if (s[l] == 'o') { r = l = l + 1; continue; }
		if (r != n && s[r] != 'o') { r++; continue; }
		sort(s.begin() + l, s.begin() + r, greater<char>());
		l = r;
	}
}

void printTransposeMatrix() {
	for (int i = 0; i < (int)G[0].size(); i++) {
		for (int j = 0; j < (int)G.size(); j++)
			cout << G[j][i];
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, m; cin >> n >> m; G.clear();
		G.resize(m, string(n, '0'));

		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> G[j][i];

		for (auto& x : G) simulateFallDown(x);

		printTransposeMatrix();
	}

	cin.ignore(2); return 0;
}