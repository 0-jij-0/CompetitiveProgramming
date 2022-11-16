#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct FT {
	int n; vector<ll> vals;
	FT(int n) : n(n), vals(n + 1, 0ll) {}

	void update(int i, ll x) {
		for (++i; i <= n; i += i & -i) vals[i] += x;
	}

	ll query(int i) const {
		ll sum = 0;
		for (++i; i; i -= i & -i) sum += vals[i];
		return sum;
	}
	ll query(int i, int j) const { return query(j) - query(i - 1); }
};

vector<int> v; int N;

ll swapAdjacent() {
	ll res = 0; FT ft(N); for (auto& x : v) 
		res += ft.query(x + 1, N - 1), ft.update(x, 1);
	return res;
}

int swapAny() {
	int res = N; vector<bool> vis(N, 0);
	for (int i = 0; i < N; i++) if(!vis[i]) {
		int cur = v[i]; --res;
		while (!vis[cur]) { vis[cur] = 1; cur = v[cur]; }
	}
	return res;
}

int moveToAny() {
	vector<int> res(N + 1, 1 << 20); res[0] = -res[0];
	for (auto& x : v) *lower_bound(res.begin(), res.end(), x) = x;
	return N - (find(res.begin(), res.end(), 1 << 20) - res.begin() - 1);
}

int moveToFront() {
	int res = N - 1;
	for (int i = N - 1; i >= 0; i--)
		if (v[i] == res) --res;
	return res + 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N; v.resize(N);
	for (auto& x : v) { cin >> x; --x; }

	cout << swapAdjacent() << ' ' << swapAny() << ' ';
	cout << moveToAny() << ' ' << moveToFront() << '\n';
}