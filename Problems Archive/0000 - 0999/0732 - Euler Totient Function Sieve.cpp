#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int SVSZ = 10000009;

int spf[SVSZ]; //Smallest Prime Factor
vector<int> primes;

void buildSieve() {
	spf[0] = spf[1] = 1;
	for (int i = 2; i < SVSZ; i++) {
		if (spf[i] == 0) { primes.push_back(i);	spf[i] = i; }
		for (int j = 0; j < int(primes.size()) && primes[j] <= spf[i] && i * primes[j] < SVSZ; j++)
			spf[i * primes[j]] = primes[j];
	}
}

vector<pair<ll, ll>> res;
ll f(ll x, ll p) { return x - x / p; }

void segmentedSieve(ll a, ll b) {
	for (int i = 0; i < (int)primes.size(); i++) {
		ll j = a; if (j % primes[i]) { j += primes[i] - (j %primes[i]); }
		for (; j <= b; j += primes[i]) {
			ll x = res[j - a].second, pk = 1;
			while (!(x % primes[i])) { pk *= primes[i]; x /= primes[i]; }
			res[j - a].first *= f(pk, primes[i]); res[j - a].second = x;
		}
	}
	for(int i = 0; i <= b - a; i++)
		if (res[i].second > 1) 
			res[i].first *= res[i].second - 1; 
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll a, b; cin >> a >> b; buildSieve();
	res.resize(b - a + 1);
	for (int i = 0; i <= b - a; i++)
		res[i] = { 1, a + i };

	segmentedSieve(a, b);
	for (int i = 0; i <= b - a; i++)
		cout << res[i].first << '\n';
	cin.ignore(2); return 0;
}