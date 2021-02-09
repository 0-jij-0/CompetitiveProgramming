#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	freopen("game.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto& x : v) { cin >> x; }
		vector<int> pref(n, 0);
		for (int i = 1; i < n; i++)
			pref[i] = v[i] > v[pref[i - 1]] ? i : pref[i - 1];

		int cur = n; bool ok = false;
		while (cur != 0) { ok = !ok; cur = pref[cur - 1]; }
		cout << (ok ? "Mike" : "Jack") << '\n';
	}
	cin.ignore(2); return 0;
}