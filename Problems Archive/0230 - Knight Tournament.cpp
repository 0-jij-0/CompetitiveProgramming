#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> res;
set<int> players;

int main() {
	int n, m; cin >> n >> m; res.resize(n + 1, 0);
	for (int i = 1; i <= n; i++) { players.insert(i); }
	for (int i = 0; i < m; i++) {
		int l, r, x; cin >> l >> r >> x;
		auto it1 = players.lower_bound(l);
		auto it2 = it1;
		while (it2 != players.end()) {
			if (*it2 > r) { break; }
			if (*it2 != x) { res[*it2] = x; }
			it2++;
		}
		players.erase(it1, it2); players.insert(x);
	}
	for (int i = 1; i <= n; i++) {
		cout << res[i];
		if (i != n) { cout << ' '; }
		else { cout << endl; }
	}
	cin.ignore(2); return 0;
}