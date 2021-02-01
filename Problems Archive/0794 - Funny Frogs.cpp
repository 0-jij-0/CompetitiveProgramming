#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

ll n, c, y;

ll findNum(ll f, ll t) {
	ll l = 0, r = 1 << 30;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if ((mid*y + f) == (t - mid)) { return mid; }
		if ((mid*y + f) < (t - mid)) { l = mid + 1; continue; }
		r = mid - 1;
	}
	if ((l*y + f) == (t - l)) { return l; }
	if ((r*y + f) == (t - r)) { return r; }
	return -1;
}

int main() {
	cin >> n >> c >> y; c--; vector<pair<ll, ll>> v(n);
	ll s = 0;
	for (int i = 0; i < n; i++) {
		int temp; cin >> temp;
		v[i] = { temp, i };
		s += temp;
	}
	sort(v.begin(), v.end()); vector<ll> steps(n, 0);

	int last = n - 1;
	if (c == v[n - 1].second) { last--; }
	for (int i = 0; i < last; i++)
		if (v[i].second != c) { steps[i] = findNum(v[i].first, v[last].first); }

	if (find(steps.begin(), steps.end(), -1) != steps.end()) { cout << "impossible" << endl; return 0; }
	cout << v[last].first << ' ' << s + v[last].first * (y - (n - 1)) << endl;
}