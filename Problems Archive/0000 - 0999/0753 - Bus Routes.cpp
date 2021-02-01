#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<ll> v; int n; ll d;

bool check(ll t) {
	ll total = t;
	for (int i = 0; i < n; i++) {
		if (total % v[i] == 0) { continue; }
		total += v[i] - (total % v[i]);
	}
	return total <= d;
}

ll findMin() {
	ll l = 0, r = d;
	while (l != r) {
		ll mid = (l + r + 1) >> 1;
		bool b = check(mid);
		b ? l = mid : r = mid - 1;
	}
	return l;
}

int main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n >> d; v.resize(n);
		for (auto &x : v) { cin >> x; }
		cout << "Case #" << t << ": " << findMin() << '\n';
	}
	cin.ignore(2); return 0;
}