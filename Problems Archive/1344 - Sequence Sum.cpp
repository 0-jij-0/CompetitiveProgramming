#include <iostream>
#include <set>
using namespace std;
typedef long long ll;

int main() {
	ll n, x; int m; cin >> n >> x >> m;
	set<ll> s; ll res = 0;
	ll cur = x; while (!s.count(cur)) {
		s.insert(cur); res += cur;
		cur = (cur * cur) % m;
	}
	set<ll> t; ll cycle = 0;
	while (!t.count(cur)) {
		t.insert(cur); cycle += cur;
		cur = (cur * cur) % m;
	}

	if (n <= (int)s.size()) {
		res = 0; while (n--) { res += x; x = (x * x) % m; }
		cout << res << '\n'; return 0;
	}
	n -= (int)s.size(); res += (n / t.size())*cycle;
	x = cur; n %= t.size();
	while (n--) { res += x; x = (x * x) % m; }
	cout << res << '\n';
	cin.ignore(2); return 0;
}