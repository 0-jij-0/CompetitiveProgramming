#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> v, idx, vis;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto& x : v) { cin >> x; }
		int i = 0; ll res = 0; while (++i < n)
			res = max(res, v[i] * v[i - 1]);

		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}
