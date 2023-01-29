#include <bits/stdc++.h>
using namespace std;

set<string> s;
vector<string> v;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, m; cin >> n >> m; v.resize(n);
	for (auto& x : v) { cin >> x; x = x.substr(3, 3); }
	while (m--) { string x; cin >> x; s.insert(x); }
	int res = 0; for (auto& x : v) res += s.count(x);
	cout << res << '\n';
}