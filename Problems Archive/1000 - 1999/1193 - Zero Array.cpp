#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> a;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, q; cin >> n >> q;
		map<int, int> m; a.resize(n);
		for (auto &x : a) { cin >> x; if(x) m[x]++; }
		while (q--) {
			int t; cin >> t;
			if (t == 2) { cout << m.size() << '\n'; continue; }
			int p, v; cin >> p >> v; p--;
			m[a[p]] > 1 ? m[a[p]]-- : m.erase(a[p]);
			a[p] = v; if (v) m[v]++;
		}
	}
	cin.ignore(2); return 0;
}