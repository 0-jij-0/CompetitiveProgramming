#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto &x : v) { cin >> x; }
		int eo = 0, oe = 0, e = 0, o = 0;
		for (int i = 0; i < n; i++) {
			(v[i] % 2 ? o : e)++;
			if (v[i] % 2 && !(i % 2)) { oe++; }
			if (!(v[i] % 2) && i % 2) { eo++; }
		}
		if (e != (n + 1) / 2 || o != n / 2) { cout << -1 << '\n'; continue; }
		cout << oe << '\n';
	}
	cin.ignore(2); return 0;
}