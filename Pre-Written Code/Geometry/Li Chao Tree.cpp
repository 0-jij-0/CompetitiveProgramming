#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1ll << 60;

struct Line {
	ll a = 1, b = 0;
	Line(ll _a, ll _b) : a(_a), b(_b) {}
	ll operator()(ll X) { return a * X + b; }
};

struct LiChaoTree {
	vector<Line> lines; int n;

	//Change these to change behavior
	LiChaoTree(int _n) : n(_n), lines((_n + 1) << 2, Line(0, INF)) {}
	ll combine(ll a, ll b) { return min(a, b); }
	bool check(ll a, ll b) { return a < b; }

	void insert(Line curLine) { insert(curLine, 0, n, 1); }
	void insert(Line curLine, int L, int R, int cur) {
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

	ll query(ll X) { return query(X, 0, n, 1); }
	ll query(ll X, int L, int R, int cur) {
		if (L == R) { return lines[L](X); }

		int M = (L + R) >> 1, left = cur << 1, right = cur << 1 | 1;
		if (X <= M) return combine(lines[cur](X), query(X, L, M, left));
		else return combine(lines[cur](X), query(X, M + 1, R, right));
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}