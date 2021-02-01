#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bitCount(int x) {
	int res = 0;
	while (x) { res++; x = x & (x - 1); }
	return res;
}

vector<int> v; int n;

vector<int> round() {
	vector<vector<int>> a(20);
	vector<int> res;
	for (int i = 0; i < n; i++)
		a[bitCount(v[i])].push_back(v[i]);
	for (auto &x : a) if(!x.empty()) {
		int ans = 0;
		for (auto &y : x) ans ^= y;
		res.push_back(ans);
	}
	return move(res);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("reduced.in", "r", stdin);

	int t; cin >> t; while (t--) {
		cin >> n; v.resize(n);
		for (auto &x : v) { cin >> x; }

		while (true) {
			vector<int> a = round();
			if (a.size() == v.size()) { break; }
			v = move(a); n = (int)v.size();
		}
		sort(v.begin(), v.end());
		for (auto &x : v) cout << x << ' '; cout << '\n';
	}
	return 0;
}