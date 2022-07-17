#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, x; cin >> n >> x; v.resize(n << 1);
		for (auto& x : v) cin >> x;
		sort(v.begin(), v.end());

		bool ok = true;
		for (int i = 0; i < n; i++)
			ok = ok && (v[i + n] - v[i] >= x);

		cout << (ok ? "YES" : "NO") << '\n';
	}
}