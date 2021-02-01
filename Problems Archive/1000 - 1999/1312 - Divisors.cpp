#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
const int SVSZ = 5000001;
const ll mod = 1000 * 1000 * 100 + 7;

int spf[SVSZ]; vector<int> primes;

void buildSieve() {
	spf[0] = spf[1] = 1;
	for (int i = 2; i < SVSZ; i++) {
		if (spf[i] == 0) { primes.push_back(i);	spf[i] = i; }
		for (int j = 0; j < int(primes.size()) && primes[j] <= spf[i] && i * primes[j] < SVSZ; j++)
			spf[i * primes[j]] = primes[j];
	}
}

ll choose2(ll x) { return (x * (x + 1)) >> 1; }

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	buildSieve(); int m = (int)primes.size();

	while (true) {
		int n; cin >> n; if (!n) { break; }
		ll res = 1; 
		for (int i = 0; i <= m && primes[i] <= n; i++) {
			ll p = primes[i], pow = 0; while (p <= n) { 
				pow += p * choose2((n / p) - 1);
				pow += (1 + (n % p)) * (n / p); 
				pow %= mod; p *= primes[i];
			}
			pow = (pow + 1) % mod; res = (res * pow) % mod; 
		}
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}