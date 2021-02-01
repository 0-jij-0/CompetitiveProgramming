#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

vector<ll> v;

int main() {
	ll n; int k; cin >> n >> k; v.resize(k);
	for (auto& x : v) { cin >> x; }

	double lim = log10(n);

	ll res = 0; for (int i = 1; i < (1 << k); i++) {
		int weight = -1; ll cur = 1;
		for (int j = 0; j < k; j++) {
			if (i & (1 << j)) { 
				if (log10(cur) + log10(v[j]) > lim) { weight = 0; break; }
				weight *= -1; cur *= v[j];
			}
		}
		if (!weight) { continue; }
		res += (n / cur) * weight;
	}
	cout << res << '\n';
	cin.ignore(2); return 0;
}