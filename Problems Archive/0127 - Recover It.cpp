#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> primes, b;

bool is_prime(int n) {
	if (n < 2) { return false; }
	if (n == 2 || n == 3) { return true; }
	if (n % 6 != 1 && n % 6 != 5) { return false; }

	int m = (int)floor(sqrt(n));
	for (int i = 3; i <= m; i += 2) {
		if (n % i == 0) { return false; }
	}
	return true;
}

void fill_primes() {
	int i = 0;
	while (primes.size() != 199999) {
		if (is_prime(i)) { primes.push_back(i); }
		i++;
	}
}

int case2(int n) {
	for (int i = 0; i < n; i++) {
		if (n % primes[i] == 0) { return n / primes[i]; }
	}
	return -1;
}

int main() {
	fill_primes(); int skip[2750132];
	int n; cin >> n;
	for (int i = 0; i < 2*n; i++) {
		int a; cin >> a; b.push_back(a); skip[a] = 0;
	}
	sort(b.begin(), b.end());
	vector<int> a;
	for (int i = b.size() - 1; i >= 0; i--) {
		int old_i = -1;
		while (i >= 0 && i != old_i) { 
			old_i = i; i -= skip[b[i]]; skip[b[old_i]] = 0;
		}
		if (i < 0) { break; }
		int &m = b[i];
		auto it = lower_bound(primes.begin(), primes.end(), m);
		if (*it == m) {
			int x = it - primes.begin() + 1;
			a.push_back(x); skip[x]++;
		}
		else {
			int x = case2(m);
			a.push_back(m); skip[x]++;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i];
		if (i + 1 != n) { cout << " "; }
		else { cout << endl; break; }
	}
	cin.ignore(2); return 0;
}