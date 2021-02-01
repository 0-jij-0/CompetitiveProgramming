#include <iostream>
#include <vector>
using namespace std;
const int SVSZ = 10000001;
int spf[SVSZ];

void buildSieve() {
	vector<int> primes; spf[0] = spf[1] = 1;
	for (int i = 2; i < SVSZ; i++) {
		if (spf[i] == 0) { primes.push_back(i);	spf[i] = i; }
		for (int j = 0; j < int(primes.size()) && primes[j] <= spf[i] && i * primes[j] < SVSZ; j++)
			spf[i * primes[j]] = primes[j];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; buildSieve();
	vector<pair<int, int>> res(n);
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		int a = spf[x]; while (x % a == 0) { x /= a; }
		if (x == 1) { res[i] = { -1, -1 }; continue; }
		res[i] = { a, x };
	}
	for (auto &x : res) { cout << x.first << ' '; } cout << '\n';
	for (auto &x : res) { cout << x.second << ' '; } cout << '\n';
	cin.ignore(2); return 0;
}