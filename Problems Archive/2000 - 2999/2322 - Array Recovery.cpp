#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto& x : v) cin >> x;

		int cur = v[0]; bool ok = true;
		for (int i = 1; i < n; i++) {
			if (v[i] && v[i - 1] - v[i] >= 0) { ok = false; break; }
			v[i] += v[i - 1];
		}

		if (!ok) { cout << "-1\n"; continue; }
		for (auto& x : v) cout << x << ' '; cout << '\n';
	}
}