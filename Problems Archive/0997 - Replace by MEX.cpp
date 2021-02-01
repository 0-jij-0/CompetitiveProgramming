#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int mex() {
	vector<int> f(v.size() + 1, 0);
	for (auto &x : v) { f[x]++; }
	return find(f.begin(), f.end(), 0) - f.begin();
}

bool dec() {
	for (int i = 1; i < (int)v.size(); i++)
		if (v[i] < v[i - 1]) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto &x : v) { cin >> x; }
		vector<int> res;
		while (dec()) {
			int m = mex(); if (m != n) { res.push_back(m); v[m] = m; continue; }
			for (int i = 0; i < n; i++) if (v[i] != i) { res.push_back(i); v[i] = m; break; }
		}
		cout << res.size() << '\n';
		for (auto &x : res) { cout << x + 1 << ' '; }
		cout << '\n';
	}
	cin.ignore(2); return 0;
}