#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int SVSZ = 1000001;

int spf[SVSZ]; //Smallest Prime Factor
vector<int> freq(SVSZ, 0), v;

void buildSieve() {
	vector<int> primes; spf[0] = spf[1] = 1;
	for (int i = 2; i < SVSZ; i++) {
		if (spf[i] == 0) { primes.push_back(i);	spf[i] = i; }
		for (int j = 0; j < int(primes.size()) && primes[j] <= spf[i] && i * primes[j] < SVSZ; j++)
			spf[i * primes[j]] = primes[j];
	}
}

ll getDivisorsHelper(int i, int curr, vector<pair<int, int>>& v, const int &x) {
	if (i == (int)v.size()) { return (curr != x) * freq[curr]; }
	ll res = getDivisorsHelper(i + 1, curr, v, x);
	for (int j = 0; j < v[i].second; j++) {
		curr *= v[i].first;
		res += getDivisorsHelper(i + 1, curr, v, x);
	}
	return res;
}

ll getDivisors(int x) {
	vector<pair<int, int>> v; int X = x;
	while (x > 1) {
		int d = spf[x], cnt = 0;
		while (x % d == 0) { x /= d; cnt++; }
		v.push_back({ d, cnt });
	}
	return getDivisorsHelper(0, 1, v, X);
}

int main() {
	freopen("find.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	buildSieve();

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		fill(freq.begin(), freq.end(), 0);
		for (auto& x : v) { cin >> x; freq[x]++; }
		sort(v.rbegin(), v.rend()); ll res = 0;
		v.erase(unique(v.begin(), v.end()), v.end());
		if (!v.back()) { res += (ll)freq[0] * (ll)(n - freq[0]); v.pop_back(); }

		for (auto& x : v) res += freq[x] * getDivisors(x);
		cout << res << '\n';
	}

	cin.ignore(2); return 0;
}