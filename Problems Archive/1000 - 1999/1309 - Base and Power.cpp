#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<pair<ll, ll>> X, Y;

void fact(ll x, vector<pair<ll, ll>> &v) {
	for (ll i = 2; i * i <= x; i++) {
		if (x % i) { continue; }
		ll c = 0; while (x % i == 0) { x /= i; c++; }
		v.push_back({ i, c });
	}
	if (x != 1) { v.push_back({ x, 1 }); }
}

bool check(ll a, ll b) {
	if (X.size() != Y.size()) { return false; }
	for (int i = 0; i < (int)X.size(); i++) {
		if (X[i].first != Y[i].first) return false;
		if (a * X[i].second != b * Y[i].second) return false;
	}
	return true;
}

int main() {
	int t; cin >> t; while (t--) {
		ll x, y, a, b; cin >> x >> a >> y >> b;
		if (a == 0 && b == 0) { cout << "Yes" << '\n'; continue; }
		X.clear(); Y.clear(); fact(x, X); fact(y, Y);
		cout << (check(a, b) ? "Yes" : "No") << '\n';
	}
	cin.ignore(2); return 0;
}