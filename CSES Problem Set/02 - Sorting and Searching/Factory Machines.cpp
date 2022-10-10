#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> v; int n, T;

bool check(ll t) {
	ll res = 0;
	for (auto &x : v) if ((res += t / x) >= T) { return true; }
	return false;
}

ll minTime() {
	ll l = 0, r = 1ll << 60;
	while (l != r) {
		ll mid = (l + r) >> 1;
		bool b = check(mid);
		b ? r = mid : l = mid + 1;
	}
	return l;
}

int main() {
	cin >> n >> T; v.resize(n);
	for (auto &x : v) { cin >> x; }
	cout << minTime() << '\n';
}