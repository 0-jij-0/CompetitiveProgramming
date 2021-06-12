#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
const int SVSZ = 1000 * 1000 * 100 + 1;

int spf[SVSZ];
int primes[5761455];

void buildSieve() {
	spf[0] = spf[1] = 1; int n = 0;
	for (int i = 2; i < SVSZ; i++) {
		if (spf[i] == 0) { primes[n++] = i;	spf[i] = i; }
		for (int j = 0; j < n && primes[j] <= spf[i] && i * primes[j] < SVSZ; j++)
			spf[i * primes[j]] = primes[j];
	}
}

int power(int x, int n) {
	int res = 1;
	for (; n; n >>= 1, x *= x)
		if (n & 1) res *= x;
	return res;
}

int main() {
	freopen("lcm.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	buildSieve();
	int t; cin >> t; while (t--) {
		int n, l, r; cin >> n >> l >> r;
		map<int, int> lcm;

		for (int i = 0; i < n; i++) {
			int x; cin >> x; while (x != 1) {
				int s = spf[x], e = 0;
				while (x % s == 0) { e++; x /= s; }
				lcm[s] = max(lcm[s], e);
			}
		}

		int K = upper_bound(primes, primes + 5761455, r) - primes;
		if (K != 0) --K; while (K != 0 && lcm.count(primes[K])) { --K; }

		int res = r, temp = 0; for (int f = max(primes[K], l); f <= r; f++) {
			int ans = 1, x = f; while(x != 1) {
				int s = spf[x], e = 0;
				while (x % s == 0) { e++; x /= s; }
				int d = lcm.count(s) ? e - lcm[s] : e;
				if (d > 0) { ans *= power(s, d); }
			}
			if (ans >= temp) { temp = ans; res = f; }
		}

		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}