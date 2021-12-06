#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

struct RMQ {
	vector<vector<ll>> rmq;
	vector<int> logb2; RMQ() {}

	ll combine(ll a, ll b) { return gcd(a, b); }

	RMQ(vector<ll>& v) { //O(nlogn) time and space
		int n = (int)v.size(); logb2.resize(n + 1, 0);
		rmq.resize(1, vector<ll>(n));
		for (int i = 0; i < n; i++) { rmq[0][i] = v[i]; }

		for (int i = 0; (1 << i) <= n; i++) { logb2[1 << i] = i; } //Precomputing Logs
		for (int i = 1; i <= n; i++) { logb2[i] = max(logb2[i], logb2[i - 1]); }
		rmq.resize(logb2.back() + 1);

		for (int t = 1; t < (int)rmq.size(); t++) {
			rmq[t].resize(n - (1 << t) + 1);
			for (int i = 0; i <= n - (1 << t); i++)
				rmq[t][i] = combine(rmq[t - 1][i], rmq[t - 1][i + (1 << (t - 1))]);
		}
	}

	ll query(int i, int j) { //O(1)
		int k = logb2[j - i + 1];
		return combine(rmq[k][i], rmq[k][j - (1 << k) + 1]);
	}
};

vector<ll> v;

int shortestGoodSegments() {
	int j = 0, n = (int)v.size();
	RMQ rmq(v); int res = n + 1;

	for (int i = 0; i < n; i++) {
		j = max(i, j);
		while (j != n && rmq.query(i, j) != 1) { j++; }
		if (j != n) res = min(res, j - i + 1);
	}
	return res == n + 1 ? -1 : res;
}

int main() {
	int n; cin >> n; v.resize(n);
	for (auto& x : v) cin >> x;

	cout << shortestGoodSegments() << '\n';
	cin.ignore(2); return 0;
}