#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
const int SVSZ = 1000009;

int spf[SVSZ]; //Smallest Prime Factor

void buildSieve() {
	vector<int> primes; spf[0] = spf[1] = 1;
	for (int i = 2; i < SVSZ; i++) {
		if (spf[i] == 0) { primes.push_back(i);	spf[i] = i; }
		for (int j = 0; j < int(primes.size()) && primes[j] <= spf[i] && i * primes[j] < SVSZ; j++)
			spf[i * primes[j]] = primes[j];
	}
}

vector<int> v; int g = 0;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

bool check() {
	set<int> p; for (auto &x : v) {
		while (x != 1) {
			int s = spf[x]; if (p.count(s)) return false;
			p.insert(s); while (x % s == 0) { x /= s; }
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; buildSieve(); v.resize(n);
	for (auto &x : v) { cin >> x; g = gcd(g, x); }
	if (g != 1) { cout << "not coprime" << '\n'; return 0; }
	cout << (check() ? "pairwise coprime" : "setwise coprime") << '\n';

	cin.ignore(2); return 0;
}