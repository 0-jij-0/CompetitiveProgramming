#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
vector<int> primes;

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

void fill(int n) {
	for (int i = 0; i <= n; i++) {
		if (is_prime(i)) { primes.push_back(i); }
	}
	v.resize(n + 1);
	for (unsigned int i = 0; i < primes.size(); i++) {
		int &a = primes[i];
		for (int j = a; j <= n; j += a) {
			v[j] = i + 1;
		}
	}
}

int main() {
	int n; cin >> n;
	fill(n);
	for (int i = 2; i <= n; i++) {
		cout << v[i];
		if (i != n) { cout << " "; }
		else { cout << endl; }
	}
	cin.ignore(2); return 0;
}