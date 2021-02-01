#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a, v;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n); bool ok = true;
		for (auto &x : v) { cin >> x; }
		a = v; sort(a.begin(), a.end());
		for (int i = 0; i < n; i++)
			if (v[i] % a[0] && v[i] != a[i]) { ok = false; break; }
		cout << (ok ? "YES" : "NO") << '\n';
	}
	cin.ignore(2); return 0;
}