#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, q; cin >> n >> q; v.resize(n);
	for (auto& x : v) {
		int L; cin >> L; x.resize(L);
		for (auto& y : x) cin >> y;
	}

	while (q--) {
		int s, t; cin >> s >> t;
		cout << v[--s][--t] << '\n';
	}
}