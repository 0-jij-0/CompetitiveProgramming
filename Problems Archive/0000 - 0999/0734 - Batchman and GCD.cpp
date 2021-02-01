/*#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int SVSZ = 100009;
const int MAXA = 20;

int spf[SVSZ]; //Smallest Prime Factor
vector<int> mult;

void buildSieve() {
	vector<int> primes; spf[0] = spf[1] = 1;
	for (int i = 2; i < SVSZ; i++) {
		if (spf[i] == 0) { primes.push_back(i);	spf[i] = i; }
		for (int j = 0; j < int(primes.size()) && primes[j] <= spf[i] && i * primes[j] < SVSZ; j++)
			spf[i * primes[j]] = primes[j];
	}
}

void getDivisorsHelper(int i, int curr, vector<pair<int, int>> &v, const int &x) {
	if (i == (int)v.size()) { mult[curr]++; return; }
	getDivisorsHelper(i + 1, curr, v, x);
	for (int j = 0; j < v[i].second; j++) {
		curr *= v[i].first;
		getDivisorsHelper(i + 1, curr, v, x);
	}
}

void getDivisors(int x) {
	vector<pair<int, int>> v; int y = x;
	while (x > 1) {
		int d = spf[x], cnt = 0;
		while (x % d == 0) { x /= d; cnt++; }
		v.push_back({ d, cnt });
	}
	getDivisorsHelper(0, 1, v, y);
}

int main() {
	int n, k; cin >> n >> k; 
	buildSieve(); mult.resize(MAXA + 1, 0);
	for (int i = 0; i < n; i++) {
		int x; cin >> x; getDivisors(x);
	}
	ll res = 0; 
	for (int i = MAXA; i >= 0; i--) {
		if (!mult[i]) { continue; }
		for (int j = 2 * i; j <= MAXA; j += i) { mult[i] -= mult[j]; }
		res += (mult[i] != 0);
	}
	cout << res << endl;
	cin.ignore(2); return 0;
}*/

#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
	int n, k; cin >> n >> k; int ans = 0;
	vector<int> d(100001, 0);
	for (int i = 0; i < n; i++) {
		int x; cin >> x; d[x]++;
	}
	for (int i = 1; i < 100001; i++) {
		vector<int> v;
		for (int j = i; j < 100001; j += i) 
			if (d[j]) { v.push_back(j / i); }

		if (v.size() > 0) {
			int g = 0;
			for (auto& u : v) {	g = gcd(g, u); }
			ans += (g == 1);
		}
	}
	cout << ans << endl;
	cin.ignore(2); return 0;
}