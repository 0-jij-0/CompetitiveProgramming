#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;

vector<int> primes;

void buildSieve(int n) {
	vector<int> spf; spf.resize(n + 1, 0);
	spf[0] = spf[1] = 1;
	for (int i = 2; i <= n; ++i) {
		if (spf[i] == 0) {
			primes.push_back(i);
			spf[i] = i;
		}
		for (int j = 0; j < int(primes.size()) && primes[j] <= spf[i] && i * primes[j] <=n ; ++j) {
			spf[i * primes[j]] = primes[j];
		}
	}
}

int main() {
	buildSieve(2000);
	int n; cin >> n;
	int p = *lower_bound(primes.begin(), primes.end(), n);
	int d = p - n; assert(d <= n / 2);
	cout << p << endl;
	for (int i = 1; i < n; i++) {
		cout << i << ' ' << i + 1 << endl;
	}
	cout << n << ' ' << 1 << endl;
	int i = 1;
	while (d != 0) {
		if (d == 1) { break; }
		cout << i << ' ' << i + 2 << endl;
		cout << i + 1 << ' ' << i + 3 << endl;
		d -= 2; i += 4;
	}
	if (d == 1) { cout << i << ' ' << i + 2 << endl; }
	cin.ignore(2); return 0;
}