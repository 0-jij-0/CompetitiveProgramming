#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<int, int> m1, m2;
vector<int> v;
vector<pair<int, int>> seg;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, k; cin >> n >> k; seg.resize(n);
	for (int i = 0; i < n; i++) {
		int l, r; cin >> l >> r;
		seg[i].first = l; seg[i].second = r;
		m1[l] = 0; m1[r] = 0;
	} 
	int i = 0;
	for (auto &x : m1) { x.second = i; m2[i] = x.first; i += 2; }
	for (auto &x : seg) { x.first = m1[x.first]; x.second = m1[x.second]; }
	v.resize(2*m1.size() + 2, 0); int pref = 0;
	for (auto &x : seg) { v[x.first]++; v[x.second + 1]--; }
	for (auto &x : v) { pref += x; x = pref; }

	vector<pair<int, int>> res;
	for (int i = 0; i < (int)v.size(); i++) {
		if (v[i] >= k) {
			pair<int, int> p(m2[i], 0);
			while (v[i] >= k) { i++; }
			p.second = m2[i - 1];
			res.push_back(p);
		}
	}
	cout << res.size() << "\n";
	for (auto &x : res)
		cout << x.first << ' ' << x.second << "\n";
	cin.ignore(2); return 0;
}