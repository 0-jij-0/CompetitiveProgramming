#include <iostream>
#include <vector>
#include <map>
using namespace std;
const int SVSZ = 10009;

int spf[SVSZ]; //Smallest Prime Factor

void buildSieve() {
	vector<int> primes; spf[0] = spf[1] = 1;
	for (int i = 2; i < SVSZ; i++) {
		if (spf[i] == 0) { primes.push_back(i);	spf[i] = i; }
		for (int j = 0; j < int(primes.size()) && primes[j] <= spf[i] && i * primes[j] < SVSZ; j++)
			spf[i * primes[j]] = primes[j];
	}
}

vector<int> a, b, c, d;

int main() {
	freopen("divisible.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	buildSieve(); int t;
	cin >> t; while (t--) {
		int n, m; cin >> n >> m;
		a.resize(n); b.resize(n);
		c.resize(m); d.resize(m);
		map<int, int> A, B;

		for (auto& x : a) { cin >> x; }
		for (auto& x : b) { cin >> x; }
		for (auto& x : c) { cin >> x; }
		for (auto& x : d) { cin >> x; }

		for(int i = 0; i < n; i++) {
			while (a[i] != 1) {
				int p = spf[a[i]], e = 0;
				while (a[i] % p == 0) { e++; a[i] /= p; }
				A[p] += e * b[i];
			}
		}

		for(int i = 0; i < m; i++) {
			while (c[i] != 1) {
				int p = spf[c[i]], e = 0;
				while (c[i] % p == 0) { e++; c[i] /= p; }
				B[p] += e * d[i];
			}
		}

		bool ok = true;
		for (auto& x : B) ok = ok && (A[x.first] >= x.second);
		cout << (ok ? "YES" : "NO") << '\n';
	}
	cin.ignore(2); return 0;
}