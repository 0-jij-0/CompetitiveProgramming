#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

struct RMQ {
	vector<vector<int>> rmq;
	vector<int> logb2; RMQ() {}
	RMQ(vector<int> &v) { //O(nlogn) time and space
		int n = (int)v.size(); logb2.resize(n + 1, 0);
		rmq.resize(1, vector<int>(n));
		for (int i = 0; i < n; i++) { rmq[0][i] = v[i]; }

		for (int i = 0; (1 << i) <= n; i++) { logb2[1 << i] = i; } //Precomputing Logs
		for (int i = 1; i <= n; i++) { logb2[i] = max(logb2[i], logb2[i - 1]); }
		rmq.resize(logb2.back() + 1);

		for (int t = 1; t < (int)rmq.size(); t++) {
			rmq[t].resize(n - (1 << t) + 1);
			for (int i = 0; i <= n - (1 << t); i++)
				rmq[t][i] = min(rmq[t - 1][i], rmq[t - 1][i + (1 << (t - 1))]);
		}
	}

	int query(int i, int j) { //O(1)
		if (i > j) { return 1 << 20; }
		int k = logb2[j - i + 1];
		return min(rmq[k][i], rmq[k][j - (1 << k) + 1]);
	}
};

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ifstream ifs("mex.in");

	int t; ifs >> t; while (t--) {
		int n, q; ifs >> n >> q; v.resize(n);
		for (auto &x : v) { ifs >> x; }
		RMQ rmq(v); while (q--) {
			int l, r; ifs >> l >> r; l--; r--;
			int L = rmq.query(0, l - 1);
			int R = rmq.query(r + 1, n - 1);
			cout << min({ n + 1, L, R }) << '\n';
		}
	}
	ifs.close(); return 0;
}