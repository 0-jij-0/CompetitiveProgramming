#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int SVSZ = 1000 * 1000 + 1;

int spf[SVSZ];

void buildSieve() {
	vector<int> primes; spf[0] = spf[1] = 1;
	for (int i = 2; i < SVSZ; i++) {
		if (spf[i] == 0) { primes.push_back(i);	spf[i] = i; }
		for (int j = 0; j < int(primes.size()) && primes[j] <= spf[i] && i * primes[j] < SVSZ; j++)
			spf[i * primes[j]] = primes[j];
	}
}

void getDivisorsHelper(int i, int curr, vector<pair<int, int>>& v, vector<int> &res) {
	if (i == (int)v.size()) { res.push_back(curr); return; }
	getDivisorsHelper(i + 1, curr, v, res);
	for (int j = 0; j < v[i].second; j++) {
		curr *= v[i].first;
		getDivisorsHelper(i + 1, curr, v, res);
	}
}

vector<int> getDivisors(int x) {
	vector<pair<int, int>> v;
	while (x > 1) {
		int d = spf[x], cnt = 0;
		while (x % d == 0) { x /= d; cnt++; }
		v.push_back({ d, cnt });
	}
	vector<int> res;
	getDivisorsHelper(0, 1, v, res);
	return move(res);
}

int findMax(int s, int cur) {
	s -= cur; if (s == 0) { return 1; }
	if (s < 2 * cur) { return -(1 << 20); }
	int res = -(1 << 20);
	for (int nextCur = 2 * cur; nextCur <= s; nextCur += cur) {
		if(s % nextCur == 0) res = max(res, 1 + findMax(s, nextCur));
	} return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	buildSieve(); int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int n; cin >> n; int res = 0;
		vector<int> divisors = getDivisors(n);
		for(auto &x : divisors) {
			if (x * (1ll << res) > n) { continue; }
			if (x < 3) { continue; }
			res = max(res, findMax(n, x));
		}
		cout << "Case #" << t << ": " << res << '\n';
	}
	cin.ignore(2); return 0;
}