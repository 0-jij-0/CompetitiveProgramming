#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
vector<ll> f;

bool isPrime(ll n) {
	if (n < 2) { return false; }
	if (n < 4) { return true; }
	if (n % 6 != 1 && n % 6 != 5) { return false; }

	for (ll i = 3; i * i <= n; i += 2)
		if (n % i == 0)
			return false;
	return true;
}

void fact(ll n) {
	for (ll i = 2; n > 1; i++) {
		if (n % i == 0) {
			ll x = 1;
			while (n % i == 0) { x *= i; n /= i; }
			f.push_back(x);
			if (n == 1) { break; }
			if (isPrime(n)) { f.push_back(n); break; }
		}
	}
}

vector<pair<ll, ll>> res;

void find_ab(int i, ll a, ll b) {
	if (i == (int)f.size()) { 
		res.push_back({ a, b }); return; 
	}
	find_ab(i + 1, a * f[i], b);
	find_ab(i + 1, a, b * f[i]);
}

bool compare(const pair<ll, ll> &p1, const pair<ll, ll> &p2) {
	return max(p1.first, p1.second) < max(p2.first, p2.second);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	ll n; cin >> n;
	if (n == 1 || isPrime(n)) {
		cout << 1 << ' ' << n << endl;
		cin.ignore(2); return 0;
	}
	fact(n); find_ab(0, 1, 1);
	pair<ll, ll> ans = *min_element(res.begin(), res.end(), compare);
	cout << ans.first << ' ' << ans.second << endl;
	cin.ignore(2); return 0;
}