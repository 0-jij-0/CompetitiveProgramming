#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, m; cin >> n >> m; v.resize(n);
		for (auto& x : v) { cin >> x; }
		sort(v.rbegin(), v.rend());

		int cur = v[0] << 1 | 1, i = 1;
		while (i != n && cur < m) {	cur += v[i++] + 1; }
		
		cout << (i == n ? "YES" : "NO") << '\n';
	}

	cin.ignore(2); return 0;
}