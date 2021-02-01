#include <iostream>
#include <cstring>
#include <numeric>
using namespace std;

int primeFactors[5000001];

void buildSieve() {
	memset(primeFactors, 0, sizeof(primeFactors));
	primeFactors[0] = primeFactors[1] = 0;
	for (int i = 2; i < 5000001; i++) {
		if (primeFactors[i]) { continue; }
		for (int j = i; j < 5000001; j += i) {
			int k = j; while (k % i == 0) { k /= i; primeFactors[j]++; }
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	buildSieve(); int t; cin >> t;
	partial_sum(primeFactors, primeFactors + 5000001, primeFactors);
	while (t--) {
		int a, b; cin >> a >> b;
		cout << primeFactors[a] - primeFactors[b] << '\n';
	}
	cin.ignore(2); return 0;
}