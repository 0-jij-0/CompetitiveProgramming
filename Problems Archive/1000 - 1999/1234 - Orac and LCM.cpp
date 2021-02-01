#include <iostream>
#include <vector>
using namespace std;
const int SVSZ = 200005;
typedef long long ll;

int spf[SVSZ]; vector<int> primes, a;

void buildSieve() {
	spf[0] = spf[1] = 1;
	for (int i = 2; i < SVSZ; i++) {
		if (spf[i] == 0) { primes.push_back(i);	spf[i] = i; }
		for (int j = 0; j < int(primes.size()) && primes[j] <= spf[i] && i * primes[j] < SVSZ; j++)
			spf[i * primes[j]] = primes[j];
	}
}

int main() {
	int n; cin >> n; a.resize(n);
	for (auto &x : a) { cin >> x; }
	buildSieve(); ll res = 1;
	for (auto &x : primes) { 
		int min1 = 1000000, min2 = 1000000;
		for (auto &y : a) {
			if (y % x && min1 == 1) { min2 = 1; break; }
			if (y % x) { swap(min2, min1); min1 = 1; continue; }
			int c = 1; while (y %x == 0) { y /= x; c *= x; }
			if (c < min1) { swap(min2, min1); min1 = c; }
			else if (c < min2) { min2 = c; }
		}
		res *= min2;
	}
	cout << res << '\n'; cin.ignore(2); return 0;
}