#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long ll;

const int N = 100005;
const ll mod = 1000 * 1000 * 1000 + 7;
int n, q, Sq, Mk;

int TIME = 0;

struct DSU {
	vector<int> parent;
	vector<vector<int>> children;
	vector<vector<pair<int, int>>> history;

	DSU(int n) : parent(n), children(n), history(n) {
		iota(parent.begin(), parent.end(), 0);
		for (int i = 0; i < n; i++) { children[i].emplace_back(i); }
	}

	inline int size(const int& u) { return (int)children[parent[u]].size(); }

	inline bool merge(int u, int v, const int &w) {
		u = parent[u]; v = parent[v]; 
		if (u == v) { return false; }
		if (size(u) > size(v)) { swap(u, v); }
		for (auto& x : children[u]) {
			history[x].push_back({ TIME, w });
			parent[x] = v; children[v].push_back(x);
		}
		TIME++; children[u].clear(); return true;
	}

	inline int query(int &u, int &v) {
		if (u == v) { return 0; }
		if (history[u].empty()) { return history[v].back().second; }
		vector<pair<int, int>>& HU = (history[u].size() > history[v].size()) ? history[v] : history[u];
		vector<pair<int, int>>& HV = (history[u].size() > history[v].size()) ? history[u] : history[v];

		int l = 0, r = HU.size();
		while (l != r) {
			int mid = (l + r) >> 1;
			int L = (HU.rbegin() + mid)->first;
			int R = (HV.rbegin() + mid)->first;
			(L == R) ? l = mid + 1 : r = mid;
		}
		if (l == (int)HU.size()) { return (HV.rbegin() + l)->second; }
		return max((HV.rbegin() + l)->second, (HU.rbegin() + l)->second);
	}
};

struct edge {
	int u, v, w; edge() {}
	edge(int _u, int _v, int _w) :
		u(_u), v(_v), w(_w) {}
	bool operator < (const edge& rhs) const { return w < rhs.w; }
};

struct node { vector<edge> edges; };

struct graph {
	vector<edge> edges; int n = 0;
	graph(int _n) : n(_n) {}

	inline void add_edge(int u, int v, int w) {
		edges.emplace_back(u, v, w);
	}

	inline void KruskalMST(DSU &dsu) {
		sort(edges.begin(), edges.end());
		int MST = 0, i = 0;
		while (MST != n - 1) {
			edge& e = edges[i]; i++;
			MST += dsu.merge(e.u, e.v, e.w);
		}
	}
};

struct point {
	int x, y, index;
	bool operator<(const point& p) const { return x == p.x ? y < p.y : x < p.x; }
};
struct nodeM { int value, p; };

point p[N];
nodeM T[N];

inline int query(int x) {
	int r = INT_MAX, p = -1;
	for (; x <= n; x += (x & -x)) {
		if (T[x].value < r) {
			r = T[x].value;
			p = T[x].p;
		}
	}
	return p;
}
inline void modify(int x, int w, int p) {
	for (; x > 0; x -= (x & -x)) {
		if (T[x].value > w) {
			T[x].value = w;
			T[x].p = p;
		}
	}
}

inline int dist(point& p1, point& p2) {
	return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

vector<int> v; int a[N];

inline void manhattan(graph &g) {
	for (int i = 1; i <= n; ++i) { p[i].index = i; }
	for (int dir = 1; dir <= 4; ++dir) {
		if (dir == 2 || dir == 4) {
			for (int i = 1; i <= n; ++i) { swap(p[i].x, p[i].y); }
		}
		else if (dir == 3) {
			for (int i = 1; i <= n; ++i) { p[i].x = -p[i].x; }
		}
		sort(p + 1, p + 1 + n);

		v.clear();
		for (int i = 1; i <= n; ++i) {
			a[i] = p[i].y - p[i].x;
			v.push_back(a[i]);
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		for (int i = 1; i <= n; ++i) { a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1; }
		for (int i = 1; i <= n; ++i) {
			T[i].value = INT_MAX;
			T[i].p = -1;
		}
		for (int i = n; i >= 1; --i) {
			int pos = query(a[i]);
			if (pos != -1) {
				g.add_edge(p[i].index - 1, p[pos].index - 1, dist(p[i], p[pos]));
			}
			modify(a[i], p[i].x + p[i].y, i);
		}
	}
}

inline bool query(int &u, int &v, int &k, DSU &dsu) {
	return dsu.query(u, v) <= k;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> q >> Sq >> Mk;
	for (int i = 1; i <= n; i++) { cin >> p[i].x >> p[i].y; }

	graph g(n);	manhattan(g); 
	DSU dsu(n); g.KruskalMST(dsu);

	ll As, Bs, Cs, At, Bt, Ct, Ak, Bk, Ck;
	cin >> As >> Bs >> Cs >> At >> Bt >> Ct >> Ak >> Bk >> Ck;

	ll ans = 0, pow2 = 2;

	ll sP, tP, kP; int s, t, k;
	sP = tP = kP = s = t = k = 0;
	while (Sq--) {
		sP = s; tP = t; kP = k; 
		cin >> s >> t >> k;	s--; t--; k++;
		ans = (ans + pow2 * (query(s, t, k, dsu))) % mod;
		s++; t++; k--; pow2 = (pow2 << 1) % mod; q--;
	}

	while (q--) {
		ll ns, nt, nk;
		ns = (As * s) + (Bs * sP) + Cs; sP = s; s = (ns % n);
		nt = (At * t) + (Bt * tP) + Ct; tP = t; t = (nt % n);
		nk = (Ak * k) + (Bk * kP) + Ck; kP = k; k = (nk % Mk) + 1;

		ans = (ans + pow2 * (query(s, t, k, dsu))) % mod;
		s++; t++; k--; pow2 = (pow2 << 1) % mod;
	}

	cout << ans << '\n'; cin.ignore(2); return 0;
}