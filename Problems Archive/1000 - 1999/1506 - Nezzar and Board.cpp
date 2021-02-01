#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

vector<ll> v;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
	int t; cin >> t; while (t--) {
		int n; ll k; cin >> n >> k; v.resize(n);
		for (auto& x : v) { cin >> x; }
		sort(v.begin(), v.end()); ll g = 0;
		for (int i = 1; i < n; i++)
			g = gcd(g, v[i] - v[i - 1]);
		if (g == 1) { cout << "YES" << '\n'; continue; }

		bool ok = false;
		for (auto& x : v) if (abs(k - x) % g == 0) { ok = true; break; }
		cout << (ok ? "YES" : "NO") << '\n';
	}
	cin.ignore(2); return 0;
}