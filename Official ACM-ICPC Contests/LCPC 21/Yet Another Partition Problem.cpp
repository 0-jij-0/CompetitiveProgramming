#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int SVSZ = 1000 * 1000 + 1;

struct StVal {
	int m = 0; StVal() {}
	StVal(const int _v) : m(_v) {}
	StVal(const StVal& L, const StVal& R) { m = max(L, R); }
	operator int() const { return m; }
};

struct StUpdate {
	int u = 0; StUpdate() {}
	StUpdate(const int v) : u(v) {}
	StUpdate(const StUpdate& oldU, const StUpdate& newU) { u = oldU + newU; }
	operator int() const { return u; }
	void apply(StVal& v, const int lo, const int hi) { v.m += u; }
};

struct SegTree {
	int n = 0; SegTree() {}
	vector<StVal> st;
	vector<StUpdate> lazy;
	vector<int> leaves;

	SegTree(const int n, vector<int> &v) : n(n), leaves(n) {
		init(1, 0, n - 1, v); lazy.resize(st.size());
	}

	void init(const int si, const int lo, const int hi, vector<int>& v) {
		if (lo == hi) {
			if (si >= (int)st.size()) st.resize(si + 1);
			st[si] = StVal(v[lo]); leaves[lo] = si;
		}
		else {
			const int mid = (lo + hi) >> 1;
			init(si << 1, lo, mid, v);
			init(si << 1 | 1, mid + 1, hi, v);
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
		}
	}

	void updateLazy(const int si, const int lo, const int hi) {
		lazy[si].apply(st[si], lo, hi);
		if (lo != hi) {
			lazy[si << 1] = StUpdate(lazy[si << 1], lazy[si]);
			lazy[si << 1 | 1] = StUpdate(lazy[si << 1 | 1], lazy[si]);
		}
		lazy[si] = StUpdate();
	}

	int query(const int l, const int r) { return  query(l, r, 1, 0, n - 1); }
	int query(const int l, const int r, const int si, const int lo, const int hi) {
		updateLazy(si, lo, hi);
		if (l <= lo && hi <= r) return st[si];

		const int mid = (lo + hi) >> 1;
		if (r <= mid) return query(l, r, si << 1, lo, mid);
		if (mid < l) return query(l, r, si << 1 | 1, mid + 1, hi);
		return StVal(query(l, r, si << 1, lo, mid), query(l, r, si << 1 | 1, mid + 1, hi));
	}

	void update(const int l, const int r, const StUpdate u) { if (l <= r) update(l, r, u, 1, 0, n - 1); }
	void update(const int l, const int r, const StUpdate& u, const int si, const int lo, const int hi) {
		if (l <= lo && hi <= r) {
			lazy[si] = StUpdate(lazy[si], u);
			updateLazy(si, lo, hi);
		}
		else {
			updateLazy(si, lo, hi);
			if (hi < l || r < lo) return;
			const int mid = (lo + hi) >> 1;
			update(l, r, u, si << 1, lo, mid);
			update(l, r, u, si << 1 | 1, mid + 1, hi);
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
		}
	}
};

int spf[SVSZ];
vector<int> v;
vector<int> dp[2];

void buildSieve() {
	vector<int> primes; spf[0] = spf[1] = 1;
	for (int i = 2; i < SVSZ; i++) {
		if (spf[i] == 0) { primes.push_back(i);	spf[i] = i; }
		for (int j = 0; j < int(primes.size()) && primes[j] <= spf[i] && i * primes[j] < SVSZ; j++)
			spf[i * primes[j]] = primes[j];
	}
}

int main() {
	freopen("splitit.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	buildSieve();

	int n, K; cin >> n >> K; v.resize(n);
	dp[0].resize(n); dp[1].resize(n);
	unordered_set<int> s;

	for (int i = 0; i < n; i++) {
		cin >> v[i]; int y = v[i];
		v[i] = 1; while (y != 1) {
			int p = spf[y], e = 0;
			while (y % p == 0) { e++; y /= p; }
			if (e & 1) v[i] *= p;
		}
		s.insert(v[i]); dp[1][i] = s.size();
	}

	for (int k = 2; k <= K; k++) {
		int cur = k & 1; SegTree prev(n, dp[cur ^ 1]);

		unordered_map<int, int> last;
		dp[cur][0] = 1; for (int i = 1; i < n; i++) {
			prev.update(last[v[i]], i - 1, 1); last[v[i]] = i;
			dp[cur][i] = prev.query(0, i - 1);
		}
	}
	cout << dp[K & 1][n - 1] << '\n';
}