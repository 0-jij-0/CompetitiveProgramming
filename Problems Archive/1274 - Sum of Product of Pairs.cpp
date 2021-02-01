#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

vector<ll> v, suf;

int main() {
	int n; cin >> n; v.resize(n); suf.resize(n);
	for (auto &x : v) { cin >> x; }
	suf.back() = v.back(); for (int i = n - 2; i >= 0; i--) suf[i] = (suf[i + 1] + v[i]) % mod;
	ll res = 0; for (int i = 0; i < n - 1; i++) {
		ll x = (v[i] * suf[i + 1]) % mod;
		res = (res + x) % mod;
	}
	cout << res << '\n';
	cin.ignore(2); return 0;
}