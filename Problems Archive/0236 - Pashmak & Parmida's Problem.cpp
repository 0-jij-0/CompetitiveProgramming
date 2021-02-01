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
		n(n), vals(vector<ll>(n + 1, 0)) {
	}

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
		if (i > j) { return 0; }
		return query(j) - query(i - 1);
	}
};

vector<int> fi, fj, v;
map<int, int> m; int n;

void map_down() {
	int i = 0; for (auto &x : v) { m[x]++; }
	for (auto &x : m) { x.second = i; i++; }
	for (auto &x : v) { x = m[x]; }
}

void compute_fij() {
	vector<int> freq; freq.resize(n, 0);
	for (int i = 0; i < n; i++) {
		freq[v[i]]++; fi[i] = freq[v[i]];
	}
	freq.clear(); freq.resize(n, 0);
	for (int j = n - 1; j >= 0; j--) {
		freq[v[j]]++; fj[j] = freq[v[j]];
	}
}

long long count_pairs() {
	FT ft(n); long long res = 0;
	for (int i = 0; i < n; i++) {
		res += ft.query(fj[i] + 1, n - 1);
		ft.update(fi[i]);
	}
	return res;
}

int main() {
	cin >> n; v.resize(n);
	fi.resize(n); fj.resize(n);
	for (auto &x : v) { cin >> x; }
	map_down(); compute_fij();
	
	cout << count_pairs() << endl;
	cin.ignore(2); return 0;
}