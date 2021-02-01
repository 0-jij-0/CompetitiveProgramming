#include <iostream>
#include <vector>
#include <assert.h>
#include <map>
using namespace std;
typedef long long ll;

struct FT {
	int n;
	vector<ll> vals;
	FT(const int n) :
		n(n), vals(vector<ll>(n + 1, 0)) {}

	void update(int i) {
		for (++i; i <= n; i += i & -i)
			vals[i]++;
	}
	ll query(int i) const { // sum from 0 ... i
		assert(i >= -1 && i < n);
		ll sum = 0;
		for (++i; i; i -= i & -i)
			sum += vals[i];
		return sum;
	}
	ll query(int i, int j) const {
		if (j < i) { return 0; }
		return query(j) - query(i - 1);
	}
};

vector<int> v;
vector<ll> gr, le;
int n; map<int, int> m;

void map_down() {
	int i = 0; for (auto &x : v) { m[x]++; }
	for (auto &x : m) { x.second = i; i++; }
	for (auto &x : v) { x = m[x]; }
}

void fill_gr() {
	FT ft(n);
	for (int i = 0; i < n; i++) {
		ft.update(v[i]);
		gr[i] = ft.query(v[i] + 1, n - 1);
	}
}
void fill_le() {
	FT ft(n);
	for (int i = n - 1; i >= 0; i--) {
		ft.update(v[i]);
		le[i] = ft.query(0, v[i] - 1);
	}
}

int main() {
	cin >> n; v.resize(n);
	gr.resize(n); le.resize(n);
	for (auto &x : v) { cin >> x; }	
	map_down(); fill_gr(); fill_le(); ll res = 0;
	for (int i = 0; i < n; i++) { res += gr[i] * le[i]; }
	cout << res << endl;

	cin.ignore(2); return 0;
}