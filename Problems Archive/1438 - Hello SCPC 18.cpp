#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v(12);

int main() {
	freopen("hello.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		for (auto& x : v) { cin >> x; }
		bool ok = true; for(int i = 1; i < 4; i++)
			if (v[i] < v[i - 1]) { ok = false; break; }
		ok = ok && (*min_element(v.begin() + 4, v.end()) > v[3]);
		cout << (ok ? "yes" : "no") << '\n';
	}
	cin.ignore(2); return 0;
}