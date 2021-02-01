#include <iostream>
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
		int k = logb2[j - i + 1];
		return min(rmq[k][i], rmq[k][j - (1 << k) + 1]);
	}
};

vector<int> v;

int main() {
	int n, q; cin >> n >> q; v.resize(n);
	for (auto &x : v) { cin >> x; }
	RMQ rmq(v); while (q--) {
		int a, b; cin >> a >> b;
		cout << rmq.query(--a, --b) << endl;
	}
	cin.ignore(2); return 0;
}