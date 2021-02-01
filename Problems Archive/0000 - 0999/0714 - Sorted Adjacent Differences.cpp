#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v, res;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; v.resize(n); res.resize(n);
		for (auto & x : v) { cin >> x; }
		sort(v.begin(), v.end());
		int i = 0, j = n - 1, k = n - 1;
		while (k >= 0) {
			res[k] = v[j]; k--; j--;
			if (k < 0) { break; }
			res[k] = v[i]; i++; k--;
		}
		for (auto &x : res) { cout << x << ' '; }
		cout << '\n';
	}
	cin.ignore(2); return 0;
}