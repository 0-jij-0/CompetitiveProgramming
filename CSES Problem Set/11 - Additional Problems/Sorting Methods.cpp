#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct FT {
	int n; vector<ll> vals;
	FT(int n) : n(n), vals(n + 1, 0ll) {}

	void update(int i, ll x) {
		for (++i; i <= n; i += i & -i) { vals[i] += x; }
	}

	ll query(int i) const { 
		ll sum = 0;
		for (++i; i; i -= i & -i) { sum += vals[i]; }
		return sum;
	}
	ll query(int i, int j) const { return query(j) - query(i - 1); }
};

vector<int> v; int N;

ll swapAdjacent() {
	ll res = 0; FT ft(N);
	for (auto& x : v) { res += ft.query(x, N - 1); ft.update(x, 1); }
	return res;
}

int swapAny() {
	int res = 0; vector<bool> vis(N, 0);
	for (int i = 0; i < N; i++) {
		if (vis[v[i]]) { continue; }
		int x = 0, cur = v[i];
		while (!vis[cur]) { vis[cur] = 1; cur = v[cur]; x++; }
		res += x - 1;
	}
	return res;
}

int moveToAny() {
	vector<int> res(N + 1, 1 << 20); res[0] = -res[0];
	for (auto& x : v) { *lower_bound(res.begin(), res.end(), x) = x; }
	return N - (find(res.begin(), res.end(), 1 << 20) - res.begin() - 1);
}

int moveToFront() {
	vector<int> idx(N);
	for (int i = 0; i < N; i++)	idx[v[i]] = i;
	int res = 0, cur = N;

	for (int i = N - 1; i >= 0; i--)
		if (idx[i] < cur) { res++; cur = idx[i]; }
		else { break; }

	return N - res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N; v.resize(N);
	for (auto& x : v) { cin >> x; --x; }

	cout << swapAdjacent() << ' ';
	cout << swapAny() << ' ';
	cout << moveToAny() << ' ';
	cout << moveToFront() << '\n';
}