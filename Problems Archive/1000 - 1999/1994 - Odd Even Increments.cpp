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

		bool ok = true;
		for (int i = 0; i < n; i += 2)
			if (abs(v[i] - v[0]) & 1) { ok = false; break; }
		for (int i = 1; i < n; i += 2)
			if (abs(v[i] - v[1]) & 1) { ok = false; break; }

		cout << (ok ? "YES" : "NO") << '\n';
	}

	cin.ignore(2); return 0;
}