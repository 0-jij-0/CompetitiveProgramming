#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
vector<ll> piles;
int n, m;

bool check(ll t) {
	vector<ll> v = piles;
	int last = n - 1;
	while (last && !v[last]) { last--; }
	for (int i = 0; i < m; i++) {
		ll time = t - last - 1;
		while (last >= 0 && v[last] <= time)
			time -= v[last--];

		if (last < 0) { break; }
		v[last] -= time;
	}
	return last < 0;
}

ll find_min_time() {
	ll l = 0, r = (ll)1e15;
	while (l != r) {
		ll mid = (l + r) >> 1;
		bool b = check(mid);
		b ? r = mid : l = mid + 1;
	}
	return l;
}

int main() {
	cin >> n >> m; piles.resize(n);
	for (auto &x : piles) { cin >> x; }

	cout << find_min_time() << endl;
	cin.ignore(2); return 0;
}