#include <bits/stdc++.h>
using namespace std;

vector<int> v, res;
multiset<int> lo, hi;

int main() {
	int n, k; cin >> n >> k; 
	v.resize(n); res.resize(n - k + 1);
	for (auto &x : v) { cin >> x; }
	for (int i = 0; i < k; i++) { lo.insert(v[i]); }
	while (hi.size() < lo.size()) { hi.insert(*lo.rbegin()); lo.erase(lo.find(*lo.rbegin())); }
	res[0] = k % 2 ? *hi.begin() : *lo.rbegin();
	for (int i = k; i < n; i++) {
		if (lo.find(v[i - k]) != lo.end()) { lo.erase(lo.find(v[i - k])); }
		else { hi.erase(hi.find(v[i - k])); }
		if (hi.empty()) { lo.insert(v[i]); }
		else { (v[i] < *hi.begin() ? lo : hi).insert(v[i]); }
		while (lo.size() < hi.size()) { lo.insert(*hi.begin()); hi.erase(hi.find(*hi.begin())); }
		while (hi.size() < lo.size()) { hi.insert(*lo.rbegin()); lo.erase(lo.find(*lo.rbegin())); }
		res[i - k + 1] = k % 2 ? *hi.begin() : *lo.rbegin();
	}
	for (auto &x : res) cout << x << ' '; cout << '\n';
}