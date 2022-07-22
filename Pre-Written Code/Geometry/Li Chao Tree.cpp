#include <iostream>
#include <vector>
#include <algorithm>
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

	//Change these to change behavior
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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}