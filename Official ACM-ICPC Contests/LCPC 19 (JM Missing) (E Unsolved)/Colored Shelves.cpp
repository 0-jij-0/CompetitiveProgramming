#include <iostream>
#include <map>
using namespace std;

int main() {
	freopen("shelves.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, s; cin >> n >> s; map<int, int> m;
		while (n--) { int x; cin >> x; m[x]++; }
		cout << m.size() << '\n';
		for (auto& x : m) cout << x.first << ' ' << (x.second + s - 1) / s << '\n';
	}
	cin.ignore(2); return 0;
}