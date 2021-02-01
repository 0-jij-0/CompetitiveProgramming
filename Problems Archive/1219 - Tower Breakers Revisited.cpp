#include <iostream>
#include <vector>
using namespace std;
const int SVSZ = 1000 * 1000 + 5;

int spf[SVSZ];

void buildSieve() {
	vector<int> primes; spf[0] = spf[1] = 1;
	for (int i = 2; i < SVSZ; i++) {
		if (spf[i] == 0) { primes.push_back(i);	spf[i] = i; }
		for (int j = 0; j < int(primes.size()) && primes[j] <= spf[i] && i * primes[j] < SVSZ; j++)
			spf[i * primes[j]] = primes[j];
	}
}

int mex(int &n) {
	int res = 0; 
	while (n != 1) { res++; n /= spf[n]; }
	return res;
}

int main() {
	int t; cin >> t; buildSieve();
	while (t--) {
		int n; cin >> n; int res = 0;
		while (n--) { int x; cin >> x; res ^= mex(x); }
		cout << (res ? 1 : 2) << '\n';
	}
	cin.ignore(2); return 0;
}