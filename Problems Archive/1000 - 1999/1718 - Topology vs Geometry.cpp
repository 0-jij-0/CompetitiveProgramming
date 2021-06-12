#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

struct Point {
	int x, y, z; Point() {}
	Point(int _x, int _y, int _z) :
		x(_x), y(_y), z(_z) {}

	bool operator < (const Point& rhs) const {
		if (x != rhs.x) { return x < rhs.x; }
		if (y != rhs.y) { return y < rhs.y; }
		return z < rhs.z;
	}

	bool operator != (const Point& rhs) const {
		return (x != rhs.x) || (y != rhs.y) || (z != rhs.z);
	}
};

struct Segment {
	Point p1, p2; Segment() {}
	Segment(Point _p1, Point _p2) {
		p1 = _p1; p2 = _p2;
		if (p2 < p1) { swap(p2, p1); }
	}

	bool operator < (const Segment& rhs) const {
		if (p1 != rhs.p1) { return p1 < rhs.p1; }
		return p2 < rhs.p2;
	}
};

struct Triangle {
	Segment s1, s2, s3;
};

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v) {
		nodes[u].edges.emplace_back(u, v);
		nodes[v].edges.emplace_back(v, u);
	}

	bool bfs(int u) {
		queue<int> q; q.push(u);
		vector<bool> visited(n, false);
		visited[u] = true; int res = 0;
		while (!q.empty()) {
			int cur = q.front(); q.pop(); res++;
			for (edge& e : nodes[cur].edges) {
				if (visited[e.v]) { continue; }
				q.push(e.v); visited[e.v] = true;
			}
		}
		return res == n;
	}
};



int main() {
	freopen("triangles.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n;
		map<Segment, int> m;
		vector<Triangle> v(n);

		for (int i = 0; i < n; i++) {
			int x1, y1, z1, x2, y2, z2, x3, y3, z3;
			cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x3 >> y3 >> z3;

			Point p1(x1, y1, z1), p2(x2, y2, z2), p3(x3, y3, z3);
			Segment s1(p1, p2), s2(p2, p3), s3(p3, p1);
			m[v[i].s1 = s1]; m[v[i].s2 = s2]; m[v[i].s3 = s3];
		}

		int id = 0; for (auto& x : m)x.second = id++;
		graph g(id); for (auto& x : v) {
			g.add_edge(m[x.s1], m[x.s2]);
			g.add_edge(m[x.s2], m[x.s3]);
			g.add_edge(m[x.s3], m[x.s1]);
		}

		cout << (g.bfs(0) ? "Yes" : "No") << '\n';
	}

	cin.ignore(2); return 0;
}