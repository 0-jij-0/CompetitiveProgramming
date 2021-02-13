#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll b, c; cin >> b >> c;
	if (b == 0) { 
		ll l1 = c >> 1;
		ll l2 = (c - 1) >> 1;
		cout << l2 + l1 + 1 << '\n';
	}
	else {
		if (c == 1) { cout << 2 << '\n'; }
		else if (c == 2) { 
			set<ll> s = { b, b - 1, -b };
			cout << s.size() << '\n';
		}
		else {
			pair<ll, ll> p1(b - (c >> 1), b + ((c - 2) >> 1));
			pair<ll, ll> p2(-b -((c - 1) >> 1), -b + ((c - 1) >> 1));

			if (p1.first > p2.first) swap(p1, p2);
			ll l1 = p1.second - p1.first + 1;
			ll l2 = p2.second - p2.first + 1;
			ll l3 = max(0ll, p1.second - p2.first + 1);
			cout << l1 + l2 - l3 << '\n';
		}
	}
	cin.ignore(2); return 0;
}