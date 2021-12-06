#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

struct RMQ {
	vector<vector<ll>> rmq;
	vector<int> logb2; RMQ() {}

	ll combine(ll a, ll b) { return min(a, b); }

	RMQ(vector<int>& v) { //O(nlogn) time and space
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
		if (i > j) { swap(i, j); }
		int k = logb2[j - i + 1];
		return combine(rmq[k][i], rmq[k][j - (1 << k) + 1]);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin.ignore(2); return 0;
}