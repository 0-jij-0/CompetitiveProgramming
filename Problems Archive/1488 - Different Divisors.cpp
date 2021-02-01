#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int SVSZ = 50001;

int spf[SVSZ]; vector<int> primes;

void buildSieve() {
	spf[0] = spf[1] = 1;
	for (int i = 2; i < SVSZ; i++) {
		if (spf[i] == 0) { primes.push_back(i);	spf[i] = i; }
		for (int j = 0; j < int(primes.size()) && primes[j] <= spf[i] && i * primes[j] < SVSZ; j++)
			spf[i * primes[j]] = primes[j];
	}
}

int main() {
	buildSieve();
	int t; cin >> t; while (t--) {
		int d; cin >> d;
		long long f = *upper_bound(primes.begin(), primes.end(), d);
		long long s = *lower_bound(primes.begin(), primes.end(), d + f);
		cout << f * s << '\n';
	}
	cin.ignore(2); return 0;
}