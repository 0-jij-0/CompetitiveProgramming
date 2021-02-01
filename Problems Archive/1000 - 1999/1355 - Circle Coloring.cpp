#include <iostream>
#include <vector>
using namespace std;

vector<int> a, b, c, p;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n; a.resize(n);
		b.resize(n); c.resize(n); p.resize(n);
		for (auto &x : a) { cin >> x; }
		for (auto &x : b) { cin >> x; }
		for (auto &x : c) { cin >> x; }

		p[0] = a[0];
		for (int i = 1; i < n - 1; i++) 
			p[i] = (a[i] == p[i - 1]) ? b[i] : a[i];
		if (a[n - 1] != p[0] && a[n - 1] != p[n - 2]) { p[n - 1] = a[n - 1]; }
		if (b[n - 1] != p[0] && b[n - 1] != p[n - 2]) { p[n - 1] = b[n - 1]; }
		if (c[n - 1] != p[0] && c[n - 1] != p[n - 2]) { p[n - 1] = c[n - 1]; }

		for (auto &x : p) cout << x << ' '; cout << '\n';
	}
	cin.ignore(2); return 0;
}