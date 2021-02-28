#include <iostream>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

vector<int> toBinary(int x) {
	vector<int> res;
	while (x) { res.push_back(x & 1); x >>= 1; }
	return move(res);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int q; cin >> q; while (q--) {
		int u, v; cin >> u >> v;
		if (u >= v) { cout << (u == v ? "YES" : "NO") << '\n'; continue; }

		vector<int> a = toBinary(u), b = toBinary(v); int n = (int)b.size();
		while (a.size() < b.size()) { a.push_back(0); }
		partial_sum(a.begin(), a.end(), a.begin());
		partial_sum(b.begin(), b.end(), b.begin());

		bool ok = true; for(int i = 0; i < n; i++)
			if (b[i] > a[i]) { ok = false; break; }

		cout << (ok ? "YES" : "NO") << '\n';
	}
	cin.ignore(2); return 0;
}