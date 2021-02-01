#include <iostream>
#include <vector>
#include <assert.h>
#include <numeric>
#include <algorithm>
using namespace std;
typedef long long ll;

struct FT {
	int n; vector<int> vals;
	FT(int n) : n(n) { vals.resize(n + 1, 0); }

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

vector<int> mi, ma, pos;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	FT ft(n + m + 1); mi.resize(n); 
	ma.resize(n); pos.resize(n);
	iota(mi.begin(), mi.end(), 0);
	iota(ma.begin(), ma.end(), 0);
	iota(pos.rbegin(), pos.rend(), 0);

	for (int i = 0; i < n; i++)
		ft.update(i, 1);

	int last = n;
	for (int i = 0; i < m; i++) {
		int a; cin >> a; a--;
		mi[a] = 0;
		ma[a] = max(ma[a], ft.query(pos[a] + 1, n + m));
		ft.update(pos[a], -1); ft.update(last, 1);
		pos[a] = last; last++;
	}

	for (int i = 0; i < n; i++)
		ma[i] = max(ma[i], ft.query(pos[i] + 1, n + m));

	for (int i = 0; i < n; i++)
		cout << mi[i] + 1 << ' ' << ma[i] + 1 << endl;

	cin.ignore(2); return 0;
}