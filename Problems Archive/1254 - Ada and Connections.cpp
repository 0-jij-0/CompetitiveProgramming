#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
typedef long long ll;
const int SVSZ = 1010001;
vector<int> primes;

int spf[SVSZ];

void buildSieve() {
	spf[0] = spf[1] = 1;
	for (int i = 2; i < SVSZ; i++) {
		if (spf[i] == 0) { primes.push_back(i);	spf[i] = i; }
		for (int j = 0; j < int(primes.size()) && primes[j] <= spf[i] && i * primes[j] < SVSZ; j++)
			spf[i * primes[j]] = primes[j];
	}
}

vector<ll> sum(SVSZ), num(SVSZ);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; buildSieve();
	for (int i = 0; i < n; i++) {
		ll x; cin >> x; sum[x] += x; num[x] += (x != 0);
	}
	partial_sum(sum.begin(), sum.end(), sum.begin());
	partial_sum(num.begin(), num.end(), num.begin());

	if (num.back() == 0) { cout << 2 << '\n'; return 0; }
	primes.resize(upper_bound(primes.begin(), primes.end(), 1000003) - primes.begin());

	ll res = n; for (auto &p : primes) {
		ll cur = sum[(p - 1) / 2];
		for (int i = p; i < SVSZ; i += p) {
			int l = i - p / 2, r = min(SVSZ - 1, i + (p - 1) / 2);
			cur += (num[i] - num[l - 1]) * ll(i) - (sum[i] - sum[l - 1]);
			cur += (sum[r] - sum[i - 1]) - (num[r] - num[i - 1]) * ll(i);
			if (cur >= res) { break; }
		}
		res = min(res, cur);
	}
	cout << res << '\n';
	cin.ignore(2); return 0;
}