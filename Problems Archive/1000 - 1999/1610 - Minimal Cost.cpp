#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, u, v; cin >> n >> u >> v; a.resize(n);
		for (auto& x : a) cin >> x;
		if (count(a.begin(), a.end(), a[0]) == n)
			cout << min(v + v, u + v) << '\n';
		else {
			bool ok = false; for(int i = 1; i < n; i++)
				if (abs(a[i] - a[i - 1]) > 1) { ok = true; break; }
			cout << (ok ? 0 : min(u, v)) << '\n';
		}
	}
	cin.ignore(2); return 0;
}