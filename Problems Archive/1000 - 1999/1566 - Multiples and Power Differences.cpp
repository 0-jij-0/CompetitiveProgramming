#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m; v.resize(n, vector<int>(m));
	for (auto& x : v) for (auto& y : x) cin >> y;

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		v[i][j] = (i + j) & 1 ? 720720 : 720720 + v[i][j] * v[i][j] * v[i][j] * v[i][j];

	for (auto& x : v) { for (auto& y : x) cout << y << ' '; cout << '\n'; }

	cin.ignore(2); return 0;
}