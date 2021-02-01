#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
typedef long long ll;

vector<ll> p, q; int n, m;

bool check(const ll &t) {
	int i = 0, j = 0; for (; i < n && j < m; i++) {
		if (p[i] < q[j]) {
			ll lim = p[i] + t;
			while (j < m && q[j] <= lim) { j++; }
		}
		else {
			if ((p[i] - q[j]) > t) { return false; }
			ll left = p[i] - q[j]; while (j < m && q[j] <= p[i]) { j++; }
			while (j < m && (left + q[j] - p[i] + min(left, q[j] - p[i])) <= t) { j++; }
		}
	}
	return j == m;
}

ll findMinTime() {
	ll l = 0, r = 1ll << 35;
	while (l != r) {
		ll mid = (l + r) >> 1;
		bool b = check(mid);
		b ? r = mid : l = mid + 1;
	}
	return l;
}

int main() {
	ifstream ifs("in.txt");
	ofstream ofs("out.txt");

	int T; ifs >> T;
	for (int t = 1; t <= T; t++) {
		int k, s; ifs >> n >> m >> k >> s;	p.resize(n); q.resize(m);
		for (int i = 0; i < k; i++) ifs >> p[i];
		ll AP, BP, CP, DP; ifs >> AP >> BP >> CP >> DP;
		for (int i = 0; i < k; i++) ifs >> q[i];
		ll AQ, BQ, CQ, DQ; ifs >> AQ >> BQ >> CQ >> DQ;
		for (int i = k; i < n; i++)	p[i] = 1 + ((p[i - 2] * AP + p[i - 1] * BP + CP) % DP);
		for (int i = k; i < m; i++) q[i] = 1 + ((q[i - 2] * AQ + q[i - 1] * BQ + CQ) % DQ);
		sort(p.begin(), p.end()); sort(q.begin(), q.end());
		ofs << "Case #" << t << ": " << findMinTime() << '\n';
	}
	return 0;
}