#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <array>
#include <cmath>
using namespace std;

vector<array<int, 2>> v;

int dist(int i, int j) {
	int dx = v[i][0] - v[j][0];
	int dy = v[i][1] - v[j][1];
	return dx * dx + dy * dy;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; v.resize(n);
	for (auto& x : v) cin >> x[0] >> x[1];

	int res = 0; for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			res = max(res, dist(i, j));

	cout << fixed << setprecision(6) << sqrt(res) << '\n';
	cin.ignore(2); return 0;
}