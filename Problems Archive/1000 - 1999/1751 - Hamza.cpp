#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v(8);

bool check() {
	if (v[0] != v[4]) { return false; } //x1 == x3
	if (v[1] != v[3]) { return false; } //y1 == y2
	if (v[5] != v[7]) { return false; } //y3 == y4
	if (v[1] <= v[5]) { return false; } //y1 > y3
	if (v[0] <= v[2]) { return false; } //x1 > x2
	if (v[4] <= v[6]) { return false; } //x3 > x4
	if (v[2] <= v[6]) { return false; } //x2 > x4
	return true;
}

int main() {
	freopen("arab.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		for (auto& x : v) { cin >> x; }
		sort(v.begin(), v.end());
		do {} while (!check() && next_permutation(v.begin(), v.end()));
		for (auto& x : v) cout << x << ' '; cout << '\n';
	}
	cin.ignore(2); return 0;
}