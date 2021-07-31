#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;

vector<array<int, 5>> v;

bool checkWinner(int i, int j) {
	int res = 0; for (int k = 0; k < 5; k++)
		res += v[i][k] < v[j][k];
	return res > 2;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		vector<int> vis(n, 0);
		for (auto& x : v) for (auto& y : x) cin >> y;
		if (n == 1) { cout << 1 << '\n'; continue; }

		int i = 0;
		while(i != n) {
			int j = i + 1;
			while (j != n && checkWinner(i, j)) { j++; }
			if (j == n) { break; }
			else { i = j; }
		}

		bool ok = true;
		for (int j = 0; j < n; j++)
			if (i != j && !checkWinner(i, j)) { ok = false; break; }

		cout << (ok ? i + 1 : -1) << '\n';
	}

	cin.ignore(2); return 0;
}