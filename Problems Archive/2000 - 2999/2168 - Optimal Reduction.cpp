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

		bool inc = true, ok = true;
		for (int i = 1; i < n; i++) {
			if (inc && v[i] >= v[i - 1]) { continue; }
			if (inc) { inc = false; continue; }
			if (v[i] > v[i - 1]) { ok = false; break; }
		}
		
		cout << (ok ? "YES" : "NO") << '\n';
	}
}