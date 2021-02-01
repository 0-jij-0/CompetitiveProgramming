#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> divisors;

bool is_prime(int n) {
	if (n < 2) { return false; }
	if (n == 2 || n == 3) { return true; }
	if (n % 6 != 1 && n % 6 != 5) { return false; }
	int m = (int) floor(sqrt(n));
	for (int i = 3; i <= m; i += 2) {
		if (n % i == 0) { return false; }
	}
	return true;
}

long long guess() {
	sort(divisors.begin(), divisors.end());
	if (divisors.size() == 1) {
		long long a = divisors[0];
		if (!is_prime(a)) { return -1; }
		return a * a;
	}
	int i = 0, j = divisors.size() - 1;
	long long a = divisors[i] * divisors[j];
	while (i <= j) {
		if (divisors[i] * divisors[j] != a) { return -1; }
		i++; j--;
	}
	int idx = 0;
	int m = (int)floor(sqrt(a));
	for (int i = 2; i <= m; i++) {
		if (a % i != 0) { continue; }
		if (i != divisors[idx]) { return -1; }
		idx++;
	}
	return a;
}

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n; cin >> n;
		divisors.clear();
		for (int j = 0; j < n; j++) {
			long long d; cin >> d;
			divisors.push_back(d);
		}
		cout << guess() << endl;
	}
	return 0;
}