#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1ll << 60;

template<class Type> struct Line {
	Type a = 1, b = 0;
	Line(Type _a, Type _b) : a(_a), b(_b) {}
	Type operator()(Type X) { return a * X + b; }
};

template<class Type> struct LiChaoTree {
	vector<Line<Type>> lines; int n;

	//Change these to toggle min/max
	LiChaoTree(int _n) : n(_n), lines((_n + 1) << 2, Line<Type>(0, INF)) {}
	Type combine(Type a, Type b) { return min(a, b); }
	bool check(Type a, Type b) { return a < b; }

	void insert(Line<Type> curLine) { insert(curLine, 0, n, 1); }
	void insert(Line<Type> curLine, int L, int R, int cur) {
		if (L == R) {
			if (check(curLine(L), lines[cur](L)))
				lines[cur] = curLine;
			return;
		}

		int M = (L + R) >> 1;
		bool left = check(curLine(L), lines[cur](L));
		bool mid = check(curLine(M), lines[cur](M));

		if (mid) { swap(lines[cur], curLine); }
		if (left != mid) insert(curLine, L, M, cur << 1);
		else insert(curLine, M + 1, R, cur << 1 | 1);
	}

	Type query(Type X) { return query(X, 0, n, 1); }
	Type query(Type X, int L, int R, int cur) {
		if (L == R) { return lines[L](X); }

		int M = (L + R) >> 1, left = cur << 1, right = cur << 1 | 1;
		if (X <= M) return combine(lines[cur](X), query(X, L, M, left));
		else return combine(lines[cur](X), query(X, M + 1, R, right));
	}
};

vector<ll> S, F;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, x; cin >> n >> x; LiChaoTree<ll> lct(1000*1000);
	S.resize(n); for (auto& x : S) cin >> x;
	F.resize(n); for (auto& x : F) cin >> x;

	vector<ll> DP(n); lct.insert(Line<ll>(x, 0));
	for (int i = 0; i < n; i++) {
		DP[i] = lct.query(S[i]);
		lct.insert(Line<ll>(F[i], DP[i]));
	}

	cout << DP.back() << '\n';
}