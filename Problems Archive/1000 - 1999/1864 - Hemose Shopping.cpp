#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v, a;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, x; cin >> n >> x; v.resize(n);
		for (auto& x : v) { cin >> x; }
		a = v; sort(a.begin(), a.end());

		bool ok = true; 
		for (int i = 0; i < n; i++) if (v[i] != a[i]) {
			if (i + x < n) { continue; }
			if (i - x >= 0) { continue; }
			ok = false; break;
		}

		cout << (ok ? "YES" : "NO") << '\n';
	}
	cin.ignore(2); return 0;
}