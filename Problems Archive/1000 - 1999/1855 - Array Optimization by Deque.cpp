#include <iostream>
#include <vector>
#include <assert.h>
#include <numeric>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;

struct FT {
	int n; vector<int> vals;
	FT(int n) : n(n), vals(n + 1, 0ll) {}

	void update(int i, int x) {
		for (++i; i <= n; i += i & -i) { vals[i] += x; }
	}

	int query(int i) const { // sum from 0 ... i
		assert(i >= -1 && i < n); int sum = 0;
		for (++i; i; i -= i & -i) { sum += vals[i]; }
		return sum;
	}
	int query(int i, int j) const { return query(j) - query(i - 1); }
};

vector<int> v, idx;
map<int, int> id;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		idx.resize(n); iota(idx.begin(), idx.end(), 0);
		for (auto& x : v) { cin >> x; }
		auto less = [&](const int& i, const int& j) {return v[i] < v[j]; };
		sort(idx.begin(), idx.end(), less);
		auto equal = [&](const int& i, const int& j) { return v[i] == v[j]; };
		idx.erase(unique(idx.begin(), idx.end(), equal), idx.end());

		int m = (int)idx.size();
		for (int i = 0; i < m; i++) id[v[idx[i]]] = i;
 
		FT ft(m); for (int i = 0; i < n; i++) { ft.update(id[v[i]], 1); }
		ll res = 0; for (int i = n - 1; i >= 0; i--) {
			int L = ft.query(0, id[v[i]] - 1);
			int R = ft.query(id[v[i]] + 1, m - 1);
			res += min(L, R); ft.update(id[v[i]], -1);
		}

		cout << res << '\n';
	}

	cin.ignore(2); return 0;
}