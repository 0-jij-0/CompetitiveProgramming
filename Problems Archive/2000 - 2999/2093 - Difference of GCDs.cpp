#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, l, r; cin >> n >> l >> r; 
		v.resize(n); bool ok = true;
		for (int i = 1; i <= n; i++) {
			int x = l + ((i - (l % i)) % i);
			if (x > r) { ok = false; break; }
			v[i - 1] = x;
		}
		if (!ok) { cout << "NO\n"; continue; }

		cout << "YES\n";
		for (auto& x : v) cout << x << ' '; cout << '\n';
	}
}