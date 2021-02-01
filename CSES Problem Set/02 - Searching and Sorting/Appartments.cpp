#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v; multiset<int> s;

int main() {
	int n, m, k; cin >> n >> m >> k; v.resize(n);
	for (auto &x : v) { cin >> x; }
	while (m--) { int x; cin >> x; s.insert(x); }
	sort(v.begin(), v.end()); int res = 0;
	for (auto &x : v) {
		auto a = s.lower_bound(x - k); if (a == s.end()) { break; }
		if (*a <= x + k) { s.erase(a); res++; }
	}
	cout << res << endl;
	cin.ignore(2); return 0;
}