#include <iostream>
#include <vector>
using namespace std;

int spf[1000009];
vector<int> primes;

void buildSieve() {
	spf[0] = spf[1] = 1;
	for (int i = 2; i < 1000009; i++) {
		if (spf[i] == 0) { primes.push_back(i);	spf[i] = i; }
		for (int j = 0; j < int(primes.size()) && primes[j] <= spf[i] && i * primes[j] < 1000009; j++)
			spf[i * primes[j]] = primes[j];
	}
}

int sum2(int t) {
	int l = 0, r = primes.size() - 1;
	while (l < r) {
		int p = primes[l] + primes[r];
		if (p == t) { return primes[r] - primes[l]; }
		else if (p < t) { l++; }
		else { primes.pop_back(); r--; }
	}
	return -1;
}

int main() {
	int x; cin >> x; 
	buildSieve(); int res = 0;
	while (x >= 4) { x = sum2(x); res++; }
	cout << res << endl;
	cin.ignore(2); return 0;
}