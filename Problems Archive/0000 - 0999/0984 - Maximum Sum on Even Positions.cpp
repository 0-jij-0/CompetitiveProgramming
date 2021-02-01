#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll maxSumSub(vector<ll> &a) {
	ll cur = 0, res = 0;
	for (auto &x : a) {
		cur += x; res = max(cur, res);
		if (cur < 0) { cur = 0; }
	}
	return res;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; vector<int>v(n);
		for (int i = 0; i < n; i++) { 
			cin >> v[i]; if (i % 2 == 0) { v[i] = -v[i]; }
		}
		vector<ll> a(n / 2, 0), b(n / 2, 0);
		for (int i = 0; i + 1 < n; i += 2)
			a[i / 2] = v[i] + v[i + 1];
		for (int i = 1; i + 1 < n; i += 2)
			b[i / 2] = v[i] + v[i + 1];

		ll res = max(maxSumSub(a), maxSumSub(b));
		for (int i = 0; i < n; i += 2) { res += -v[i]; }
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}