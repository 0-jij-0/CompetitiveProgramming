#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	int t; cin >> t; while (t--) {
		ll p, f; cin >> p >> f;
		ll cnts, cntw; cin >> cnts >> cntw;
		ll s, w; cin >> s >> w;
		if (s > w) { swap(s, w); swap(cnts, cntw); }

		ll x = p + f;
		ll numS = min(cnts, x / s);
		x -= numS * s;
		ll numW = min(cntw, x / w);
		bool ok = false;

		for (ll i = 0; i <= numS; i++) {
			ll P = p - i * s, F = f - (numS - i) * s;
			if (F < 0) { continue; }
			if (P < 0) { break; }
			if (((P / w) + (F / w)) >= numW) { ok = true; break; }
		}
		cout << numS + numW - (ok == false) << '\n';
	}
	cin.ignore(2); return 0;
}