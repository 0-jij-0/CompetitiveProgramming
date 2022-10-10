#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;
multiset<int> s;

int main() {
	int n, k; cin >> n >> k; v.resize(n);
	for (auto& x : v) cin >> x.second >> x.first;
	sort(v.begin(), v.end()); int res = 0;
	for (int i = 0; i < k; i++) s.insert(0);

	for (int i = 0; i < n; i++) {
		auto it = s.upper_bound(v[i].second);
		if (it == s.begin()) { continue; }
		--it; s.erase(it); s.insert(v[i].first); res++;
	}

	cout << res << '\n';
}