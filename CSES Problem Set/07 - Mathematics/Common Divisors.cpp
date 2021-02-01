#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int SVSZ = 1000009;

int spf[SVSZ]; //Smallest Prime Factor
vector<int> primes; int res = 0;
vector<bool> p(SVSZ, false);

void buildSieve() {
	vector<int> primes; spf[0] = spf[1] = 1;
	for (int i = 2; i < SVSZ; i++) {
		if (spf[i] == 0) { primes.push_back(i);	spf[i] = i; }
		for (int j = 0; j < int(primes.size()) && primes[j] <= spf[i] && i * primes[j] < SVSZ; j++)
			spf[i * primes[j]] = primes[j];
	}
}

void getDivisorsHelper(int i, int curr, vector<pair<int, int>> &v) {
	if (i == (int)v.size()) { 
		if (p[curr]) { res = max(res, curr); }
		p[curr] = true; return;
	}
	getDivisorsHelper(i + 1, curr, v);
	for (int j = 0; j < v[i].second; j++) {
		curr *= v[i].first;
		getDivisorsHelper(i + 1, curr, v);
	}
}

void getDivisors(int x) {
	vector<pair<int, int>> v;
	while (x > 1) {
		int d = spf[x], cnt = 0;
		while (x % d == 0) { x /= d; cnt++; }
		v.push_back({ d, cnt });
	}
	getDivisorsHelper(0, 1, v);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; buildSieve();
	while (n--) { int x; cin >> x; getDivisors(x); }
	cout << res << endl; cin.ignore(2); return 0;
}