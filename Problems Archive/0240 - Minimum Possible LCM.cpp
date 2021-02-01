#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> table[10000009];
vector<int> v, indexes;
int spf[10000009];

void getDivisorsHelper(int i, int curr, const vector<pair<int, int>> &v, int idx) {
	if (i == (int)v.size()) {
		pair<int, int> &p = table[curr];
		if (!p.first) { p.first = idx; }
		else if (!p.second) { p.second = idx; }
	}
	else {
		getDivisorsHelper(i + 1, curr, v, idx);
		for (int j = 0; j < v[i].second; ++j) {
			curr *= v[i].first;
			getDivisorsHelper(i + 1, curr, v, idx);
		}
	}
}

void getDivisors(int x, const int idx) {
	vector<pair<int, int>> v;
	while (x > 1) {
		int d = spf[x], cnt = 0;
		while (x % d == 0) { x /= d; cnt++; }
		v.push_back({ d, cnt });
	}
	getDivisorsHelper(0, 1, v, idx);
}

void buildSieve() {
	vector<int> primes;
	spf[0] = spf[1] = 1;
	for (int i = 2; i < 10000009; ++i) {
		if (spf[i] == 0) {
			primes.push_back(i);
			spf[i] = i;
		}
		for (int j = 0; j < int(primes.size()) && primes[j] <= spf[i] && i * primes[j] < 10000009; ++j) {
			spf[i * primes[j]] = primes[j];
		}
	}
}

bool comp(int i, int j) { return v[i] < v[j]; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	buildSieve();
	int n; cin >> n; v.resize(n + 1); indexes.resize(n + 1);
	for (int i = 1; i <= n; i++) { cin >> v[i]; indexes[i] = i; }
	sort(indexes.begin() + 1, indexes.end(), comp);
	for (int i = 1; i < (int)indexes.size(); i++) { getDivisors(v[indexes[i]], indexes[i]); }
	pair<long long, pair<int, int>> res = { 1ll << 60, {-1, -2} };
	for (int i = 1; i < 10000009; i++) {
		pair<int, int> &p = table[i];
		if (!p.second) { continue; }
		res = min(res, { (long long) v[p.first] * v[p.second] / i, p });
	}
	int i = res.second.first, j = res.second.second;
	if (i > j) { swap(i, j); }
	cout << i << ' ' << j << endl;
	cin.ignore(2); return 0;
}