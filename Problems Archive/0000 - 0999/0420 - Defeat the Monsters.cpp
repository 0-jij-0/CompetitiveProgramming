#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int spf[1000009];
vector<int> v, p;

void buildSieve() {
	vector<int> primes; spf[0] = spf[1] = 1;
	for (int i = 2; i < 1000009; i++) {
		if (spf[i] == 0) { primes.push_back(i);	spf[i] = i; }
		for (int j = 0; j < int(primes.size()) &&
			primes[j] <= spf[i] && i * primes[j] < 1000009; j++)
			spf[i * primes[j]] = primes[j];
	}
}

void factorize(int x) {
	while (x != 1) {
		int d = spf[x]; p[d]++;
		while (x % d == 0) { x /= d; }
	}
}

int main() {
	int t; cin >> t; buildSieve();
	while (t--) {
		int n; cin >> n; v.resize(n);
		p.clear(); p.resize(1000001, 0);
		for (auto &x : v) { cin >> x; factorize(x); }
		int res = 0;
		for (auto &x : p) { res += (x + 2) / 3; }
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}