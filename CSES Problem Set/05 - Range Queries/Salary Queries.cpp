#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<char, pair<int, int>> query;

map<int, int> comp; vector<int> v;
vector<query> queries;

struct FT {
	int n; vector<ll> vals;
	FT(int n) : n(n), vals(n + 1, 0ll) {}

	void update(int i, ll x) {
		for (++i; i <= n; i += i & -i) { vals[i] += x; }
	}

	ll query(int i) const { // sum from 0 ... i
		ll sum = 0;
		for (++i; i; i -= i & -i) { sum += vals[i]; }
		return sum;
	}
	ll query(int i, int j) const { return query(j) - query(i - 1); }
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, q; cin >> n >> q;
	v.resize(n); queries.resize(q);
	for (auto &x : v) { cin >> x; comp[x]; }
	for (auto &x : queries) {
		cin >> x.first >> x.second.first >> x.second.second;
		if (x.first == '!') comp[x.second.second];
	}

	int id = 0; for (auto &x : comp) x.second = id++;
	FT ft(id); for (auto &x : v) { ft.update(x = comp[x], 1); }
	for (auto &q : queries) {
		if (q.first == '!') {
			q.second.first--; q.second.second = comp[q.second.second];
			int &x = v[q.second.first];	ft.update(x, -1); 
			x = q.second.second; ft.update(x, 1);
		}
		else {
			if (q.second.second < comp.begin()->first) { cout << 0 << '\n'; continue; }
			int l = comp.lower_bound(q.second.first)->second;
			int r = (--comp.upper_bound(q.second.second))->second;
			cout << ft.query(l, r) << '\n';
		}
	}
}