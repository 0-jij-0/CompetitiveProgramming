#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<ll> v;

int main() {
	int t; cin >> t; while (t--) {
		ll n, x; cin >> n >> x; v.resize(n);
		for (auto &x : v) { cin >> x; }
		ll mi = 35, ind = -1;
		for (int i = 0; i < n; i++) {
			ll num = 1;	ll temp = v[i];
			while (temp % x == 0) { num++; temp /= x; }
			if (num < mi) { mi = num; ind = i; }
		}
		ll res = 0;
		for (int i = 0; i < ind; i++) { res += v[i] * (mi + 1); }
		for (int i = ind; i < n; i++) { res += (v[i] * mi); }
		cout << res << endl;
	}

	cin.ignore(2); return 0;
}