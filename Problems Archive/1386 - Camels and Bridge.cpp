#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

vector<ll> w, l, v;

int lowest(int n) {
	int i = 0; while (!(n & (1 << i))) { i++; }
	return i;
}

int highest(int n) {
	int i = 9; while (!(n & (1 << i))) { i--; }
	return i;
}

int main() {
	int n, m; cin >> n >> m; w.resize(n);
	v.resize(m); l.resize(m);
	for (auto &x : w) { cin >> x; }
	for (int i = 0; i < m; i++)
		cin >> l[i] >> v[i];

	ll maW = *max_element(w.begin(), w.end());
	ll miV = *min_element(v.begin(), v.end());

	if (maW > miV) { cout << -1 << '\n'; return 0; }

	vector<ll> c(1 << n, 0);
	for (int i = 1; i < (1 << n); i++) {
		ll W = 0; for (int j = 0; j < n; j++) W += ((i & (1 << j)) != 0) * w[j];
		for (int j = 0; j < m; j++) if (W > v[j]) c[i] = max(c[i], l[j]);
	}

	vector<int> p(n); iota(p.begin(), p.end(), 0);
	ll res = 1ll << 60; while (true) {
		//for (auto &x : p) cout << x << ' '; cout << '\n';
		vector<ll> X(n, 0);
		for (int i = 1; i < (1 << n); i++) {
			if (!(i & (i - 1))) { continue; }

			int mask = 0; for (int j = 0; j < n; j++) {
				if (i & (1 << j)) mask |= (1 << p[j]);
			}

			int low = lowest(i), high = highest(i);
			X[high] = max(X[high], X[low] + c[mask]);
		}
		//for (auto &x : X) cout << x << ' '; cout << '\n';
		res = min(res, X.back());
		if(!next_permutation(p.begin(), p.end())) break;
	}
	cout << res << '\n';
	cin.ignore(2); return 0;
}