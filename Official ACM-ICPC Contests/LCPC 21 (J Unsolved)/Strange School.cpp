#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> a, e1, b1, e2, b2;

int main() {
	freopen("school.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; ll S, x; cin >> n >> S >> x;
		a.resize(n); for (auto& x : a) { cin >> x; }
		e1.resize(n); for (auto& x : e1) { cin >> x; }
		b1.resize(n); for (auto& x : b1) { cin >> x; }
		e2.resize(n); for (auto& x : e2) { cin >> x; }
		b2.resize(n); for (auto& x : b2) { cin >> x; }

		ll res = 0; for (int i = 0; i < n; i++) {
			ll dontEatTime = a[i] + b2[i], eatTime = a[i] + b1[i] + b2[i];
			ll dontEatEnergy = (dontEatTime > S) ? e2[i] - x : e2[i];
			ll eatEnergy = (eatTime > S) ? e2[i] + e1[i] - x : e2[i] + e1[i];
			res += max(dontEatEnergy, eatEnergy);
		}
		cout << res << '\n';
	}

	cin.ignore(2); return 0;
}