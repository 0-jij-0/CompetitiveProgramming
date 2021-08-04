#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> v, d;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

struct RMQ {
	vector<vector<ll>> rmq;
	vector<int> logb2; RMQ() {}
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
				rmq[t][i] = gcd(rmq[t - 1][i], rmq[t - 1][i + (1 << (t - 1))]);
		}
	}

	ll query(int i, int j) { //O(1)
		if (i > j) { swap(i, j); }
		int k = logb2[j - i + 1];
		return gcd(rmq[k][i], rmq[k][j - (1 << k) + 1]);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n); d.resize(n - 1);
		for (auto& x : v) { cin >> x; }
		for (int i = 0; i < n - 1; i++)
			d[i] = abs(v[i] - v[i + 1]);

		int res = 0; RMQ rmq(d);
		for (int i = 0; i < n - 1; i++) {
			int l = i, r = n - 1;
			while (l != r) {
				int mid = (l + r) >> 1;
				ll g = rmq.query(i, mid);
				g == 1 ? r = mid : l = mid + 1;
			}
			res = max(res, l - i);
		}
		cout << res + 1 << '\n';
	}
	cin.ignore(2); return 0;
}