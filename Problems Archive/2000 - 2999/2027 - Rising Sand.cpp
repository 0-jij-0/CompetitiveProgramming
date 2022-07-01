#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, k; cin >> n >> k; v.resize(n);
		for (auto& x : v) cin >> x;

		if (k == 1) { cout << (n - 1) / 2 << '\n'; continue; }
		int res = 0; for (int i = 1; i < n - 1; i++)
			res += (v[i] > v[i - 1] + v[i + 1]);

		cout << res << '\n';
	}
}