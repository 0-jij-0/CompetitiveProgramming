#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n;
		vector<int> res(n); int e = 0, o = 0;
		iota(res.begin(), res.end(), 0);
		for (int i = 0; i < n - 2; i++)
			(i & 1 ? o : e) ^= res[i];

		if (e == o) { res[0] = n; e ^= n; }

		if (n & 1) { res[n - 1] = (1 << 30) | e; res[n - 2] = (1 << 30) | o; }
		else { res[n - 2] = (1 << 30) | e; res[n - 1] = (1 << 30) | o; }
		for (auto& x : res) cout << x << ' '; cout << '\n';
	}
}