#include <iostream>
#include <set>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	multiset<int, greater<int>> s;
	while (n--) { int x; cin >> x; s.insert(x); }
	while (m--) {
		int p; cin >> p;
		auto it = s.lower_bound(p);
		if (it == s.end()) { cout << -1 << '\n'; continue; }
		cout << *it << '\n'; s.erase(it);
	}
	cin.ignore(2); return 0;
}