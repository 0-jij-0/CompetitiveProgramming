#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct C { int t, l, h; C() {} };
vector<C> v;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m; v.resize(n);
		for (auto &x : v) { cin >> x.t >> x.l >> x.h; }
		int t = 0, minT = m, maxT = m; bool b = true;
		for (int i = 0; i < n; i++) {
			int dt = v[i].t - t; minT -= dt; maxT += dt; t = v[i].t;
			if (minT > v[i].h || maxT < v[i].l) { b = false; break; }
			minT = max(minT, v[i].l); maxT = min(maxT, v[i].h);
		}
		cout << (b ? "YES" : "NO") << endl;
	}
	cin.ignore(2); return 0;
}