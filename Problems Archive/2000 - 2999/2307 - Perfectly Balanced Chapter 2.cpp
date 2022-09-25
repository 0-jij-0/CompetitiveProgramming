#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod1 = 1000 * 1000 * 1000 + 7;
const ll mod2 = 998244353;

vector<int> A;

ll power(ll x, ll n, ll P) {
	ll res = 1;
	for (; n; n >>= 1, x = (x * x) % P)
		if (n & 1) res = (res * x) % P;
	return res;
}

ll modInv(ll x, ll P) { return power(x, P - 2, P); }

struct StVal {
	ll sum = 0, xorSum = 0, p1 = 1, p2 = 1; StVal() {}
	StVal(ll v) : sum(v), xorSum(v), p1(v), p2(v) {}
	StVal(const StVal& L, const StVal& R) { 
		sum = L.sum + R.sum;
		xorSum = L.xorSum ^ R.xorSum;
		p1 = (L.p1 * R.p1) % mod1;
		p2 = (L.p2 * R.p2) % mod2;
	}
};

struct SegTree {
	int n;
	vector<StVal> st;
	vector<int> leaves;

	SegTree(int n) : n(n), leaves(n) { init(1, 0, n - 1); }

	void init(int si, int lo, int hi) {
		if (lo == hi) {
			if (si >= (int)st.size()) st.resize(si + 1);
			st[si] = StVal(A[lo]); leaves[lo] = si;
		}
		else {
			const int mid = (lo + hi) >> 1;
			init(si << 1, lo, mid);
			init(si << 1 | 1, mid + 1, hi);
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
		}
	}

	StVal query(int l, int r) { return (l <= r && l < n&& r >= 0) ? query(l, r, 1, 0, n - 1) : StVal(); }
	StVal query(int l, int r, int si, int lo, int hi) {
		if (l <= lo && hi <= r) return st[si];

		const int mid = (lo + hi) >> 1;
		if (r <= mid) return query(l, r, si << 1, lo, mid);
		if (mid < l) return query(l, r, si << 1 | 1, mid + 1, hi);
		return StVal(query(l, r, si << 1, lo, mid), query(l, r, si << 1 | 1, mid + 1, hi));
	}

	//Currently Incremental Point Updates
	void update(int i, int x) {
		int si = leaves[i]; st[si] = StVal(x);
		for (si >>= 1; si; si >>= 1)
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
	}
};

bool isAlmostPerfectlybalanced(const StVal& L, const StVal& R, int mid) {
	ll diffL = L.sum + mid - R.sum;
	ll xorDiff = L.xorSum ^ mid ^ R.xorSum;
	ll p1DiffL = (((L.p1 * mid) % mod1) * modInv(R.p1, mod1)) % mod1;
	ll p2DiffL = (((L.p2 * mid) % mod2) * modInv(R.p2, mod2)) % mod2;

	if (diffL == xorDiff && diffL == p1DiffL && diffL == p2DiffL) return true;

	ll diffR = R.sum + mid - L.sum;
	ll p1DiffR = (((R.p1 * mid) % mod1) * modInv(L.p1, mod1)) % mod1;
	ll p2DiffR = (((R.p2 * mid) % mod2) * modInv(L.p2, mod2)) % mod2;

	return (diffR == xorDiff && diffR == p1DiffR && diffR == p2DiffR);
}

int main() {
	ifstream cin("perfectly_balanced_chapter_2_input.txt");
	ofstream cout("perfectly_balanced_chapter_2_output.txt");
	ios::sync_with_stdio(0);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int n; cin >> n; A.resize(n);
		for (auto& x : A) cin >> x;

		SegTree st(n); int res = 0;
		int q; cin >> q; while (q--) {
			int qt; cin >> qt; if (--qt) {
				int L, R; cin >> L >> R;
				if ((--R - --L) & 1) { continue; }
				if (R == L) { res++; continue; }
				int M = (L + R) >> 1;
				res += isAlmostPerfectlybalanced(st.query(L, M - 1), st.query(M + 1, R), A[M]);
			}
			else {
				int x, y; cin >> x >> y;
				st.update(--x, y); A[x] = y;
			}
		}
		cout << "Case #" << t << ": " << res << '\n';
	}
}