#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <numeric>
using namespace std;

int spf[100009];

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

vector<int> mult[100001];

void buildSieve() {
	vector<int> primes; spf[0] = spf[1] = 1;
	for (int i = 2; i < 100009; i++) {
		if (spf[i] == 0) { primes.push_back(i);	spf[i] = i; }
		for (int j = 0; j < int(primes.size()) && primes[j] <= spf[i] && i * primes[j] < 100009; j++)
			spf[i * primes[j]] = primes[j];
	}
}

void getDivisorsHelper(int idx, int i, int curr, vector<pair<int, int>> &v) {
	if (i == (int)v.size()) { 
		mult[curr].push_back(idx); return;
	}
	getDivisorsHelper(idx, i + 1, curr, v);
	for (int j = 0; j < v[i].second; j++) {
		curr *= v[i].first;
		getDivisorsHelper(idx, i + 1, curr, v);
	}
}

void getDivisors(int x, int idx) {
	vector<pair<int, int>> v;
	while (x > 1) {
		int d = spf[x], cnt = 0;
		while (x % d == 0) { x /= d; cnt++; }
		v.push_back({ d, cnt });
	}
	getDivisorsHelper(idx, 0, 1, v);
}

struct DSU {
	vector<int> rank, parent;

	DSU(int n) {
		rank.resize(n, 1); parent.resize(n);
		iota(parent.begin(), parent.end(), 0);
	}

	int find(const int u) { return parent[u] == u ? u : (parent[u] = find(parent[u])); }
	int size(int u) { return rank[find(u)]; }

	bool merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) { return false; }
		if (rank[u] < rank[v]) { swap(u, v); }
		rank[u] += rank[v];	parent[v] = u;
		return true;
	}
};

vector<int> v;

int main() {
	ifstream ifs("dream.in");
	int T; ifs >> T; buildSieve();
	for (int t = 1; t <= T; t++) {
		int n; ifs >> n; v.resize(n);
		for (auto &x : mult) { x.clear(); }
		for (auto &x : v) { ifs >> x; }
		for (int i = 0; i < n; i++)
			getDivisors(v[i], i);
		DSU dsu(n); int res = 0;
		for (int i = 100000; i > 0; i--) {
			if (mult[i].size() < 2) { continue; }
			for (int j = 1; j < (int)mult[i].size(); j++) {
				if (!dsu.merge(mult[i][j], mult[i][j - 1])) { continue; }
				res += i;
			}
		}
		cout << "Case " << t << ": " << res << endl;
	}
	cin.ignore(2); return 0;
}