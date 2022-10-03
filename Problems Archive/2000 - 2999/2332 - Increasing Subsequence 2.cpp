#include <bits/stdc++.h>
using namespace std;
const int mod = 1000 * 1000 * 1000 + 7;

struct FT {
	int n; vector<int> vals;
	FT(int n) : n(n), vals(n + 1, 0ll) {}

	void update(int i, int x) {
		for (++i; i <= n; i += i & -i) 
			vals[i] = (vals[i] + x) % mod;
	}

	int query(int i) {
		int sum = 0; for (++i; i; i -= i & -i)
			sum = (sum + vals[i]) % mod;
		return sum;
	}
	int query(int i, int j) {
		return (query(j) - query(i - 1) + mod) % mod;
	}
};

map<int, vector<int>, greater<int>> idx;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; 
	for (int i = 0; i < n; i++) {
		int x; cin >> x; idx[x].push_back(i);
	}

	FT ft(n); int res = 0; 
	for (auto& [k, x] : idx) for(auto &y : x) {
		int cont = 1 + ft.query(y + 1, n - 1);
		res = (res + cont) % mod; ft.update(y, cont);
	}
	cout << res << '\n';
}