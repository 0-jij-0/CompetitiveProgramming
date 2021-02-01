#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> v;

int main() {
	ifstream ifs("in.txt");
	ofstream ofs("out.txt");

	int T; ifs >> T;
	for (int t = 1; t <= T; t++) {
		int n, m; ifs >> n >> m; v.resize(n);
		for (auto &x : v) { ifs >> x; }
		deque<ll> dq; vector<ll> res(n, 0);
		for (int i = 0; i <= min(m, n - 1); i++) {
			if (v[i] == 0) { continue; }
			while (!dq.empty() && dq.back() > v[i]) { dq.pop_back(); }
			dq.push_back(v[i]);			
		}
		bool ok = true;
		for (int i = m + 1; i < n; i++) {
			if (v[i - m - 1] + res[i - m - 1] == dq.front()) { dq.pop_front(); }
			if (dq.empty()) { ok = false; break; }
			res[i] = dq.front(); if (v[i] == 0) { continue; }
			while (!dq.empty() && dq.back() > res[i] + v[i]) { dq.pop_back(); }
			dq.push_back(res[i] + v[i]);
		}
		ofs << "Case #" << t << ": " << (ok ? res.back() : -1ll) << '\n';
	}
	cin.ignore(2); return 0;
}