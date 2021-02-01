#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> v;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto &x : v) { cin >> x; }
		int i = 0, j = 0; ll res = 0, m = v[0];
		while (j != n) {
			if (v[i] * v[j] > 0) { m = max(m, v[j]); j++; continue; }
			res += m; i = j; m = v[j]; j++;
		}
		cout << res + m << endl;
	}
	cin.ignore(2); return 0;
}