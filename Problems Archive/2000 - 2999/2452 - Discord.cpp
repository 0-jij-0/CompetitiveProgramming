#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> A;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, m; cin >> n >> m;
	A.resize(m, vector<int>(n));
	for (auto& x : A) for (auto& y : x) { cin >> y; --y; }

	vector<vector<int>> bad_mood(n, vector<int>(n, 1));
	for (int i = 0; i < m; i++) for (int j = 1; j < n; j++)
		bad_mood[A[i][j]][A[i][j - 1]] = bad_mood[A[i][j - 1]][A[i][j]] = 0;

	int res = 0; for (auto& x : bad_mood)
		res += count(x.begin(), x.end(), 1);

	cout << (res - n) / 2 << '\n';
}