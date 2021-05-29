#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v, res;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n << 1);
		for (auto& x : v) { cin >> x; }
		sort(v.begin(), v.end()); res.resize(n << 1);
		for (int i = 0; i < n; i++)
			res[i << 1 | 1] = v[i];
		for (int i = n; i < (n << 1); i++)
			res[(i - n) << 1] = v[i];

		for (auto& x : res) cout << x << ' '; cout << '\n';
	}

	cin.ignore(2); return 0;
}