#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
const int SVSZ = 10000001;
typedef int(*func_ptr) (int&, int&, int&);

int spf[SVSZ]; //Smallest Prime Factor

void buildSieve() {
	vector<int> primes; spf[0] = spf[1] = 1;
	for (int i = 2; i < SVSZ; i++) {
		if (spf[i] == 0) { primes.push_back(i);	spf[i] = i; }
		for (int j = 0; j < int(primes.size()) && primes[j] <= spf[i] && i * primes[j] < SVSZ; j++)
			spf[i * primes[j]] = primes[j];
	}
}

ll power(ll x, ll n) {
	ll res = 1;
	for (; n; n >>= 1, x *= x)
		if (n & 1) res *= x;
	return res;
}

int main() {
	freopen("scientist.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	buildSieve();
	int t; cin >> t; while (t--) {
		int n; cin >> n; int N = n;
		map<int, int> m; while (n--) {
			int x; cin >> x; while (x != 1) {
				int s = spf[x], e = 0;
				while (x % s == 0) { x /= s; e++; }
				m[s] += e;
			}
		}
		ll res = 1; for (auto& x : m)
			res *= power(x.first, ((N + 1) - (x.second % (N + 1))) % (N + 1));

		cout << res << '\n';
	}

	cin.ignore(2); return 0;
}