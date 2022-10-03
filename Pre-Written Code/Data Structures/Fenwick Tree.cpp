#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct FT {
	int n; vector<ll> vals;
	FT(int n) : n(n), vals(n + 1, 0ll) {}

	void update(int i, ll x) {
		for (++i; i <= n; i += i & -i) vals[i] += x;
	}

	ll query(int i) { // sum from 0 ... i
		ll sum = 0;
		for (++i; i; i -= i & -i) sum += vals[i];
		return sum;
	}
	ll query(int i, int j) { return query(j) - query(i - 1); }
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

}