#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;

vector<int> v; 
vector<ll> recTime, res;

struct edge {
	int u, v, id; edge() {}
	edge(int _u, int _v, int _id) :
		u(_u), v(_v), id(_id) {}
};

struct node { vector<edge> edges; };

struct val {
	int v, id, p; val() {}
	val(int _v, int _id, int _p) :
		v(_v), id(_id), p(_p) {}
	bool operator < (const val &rhs) const { return v < rhs.v; }
};

struct compVal {
	bool operator ()(const val &v1, const val &v2) const {
		return v1.v > v2.v;
	}
};

struct graph {
	vector<node> nodes; int n;
	vector<edge> edges; int m;
	graph(int _n) : n(_n) { nodes.resize(n); m = 0; }

	void add_edge(int u, int v) {
		edge e1(u, v, m), e2(v, u, m + 1);
		nodes[u].edges.push_back(e1); m++;
		nodes[v].edges.push_back(e2); m++;
		edges.push_back(e1); edges.push_back(e2);
	}

	void bfs() {
		priority_queue<val> pqNeg;
		priority_queue<val, vector<val>, compVal> pqPos;
		recTime[0] = 0; vector<bool> visited(n, false); visited[0] = true;
		for (auto &x : nodes[0].edges) {
			visited[x.v] = true;
			if (v[x.v] < 0) { pqNeg.push(val(v[x.v], x.v, 0)); }
			else { pqPos.push(val(v[x.v], x.v, 0)); }
		}

		int vis = 1; ll longest = 0; bool b = false;
		while (!pqPos.empty() || !pqNeg.empty()) {
			vector<val> cand;
			if (!pqNeg.empty() && -pqNeg.top().v == vis) {
				int y = pqNeg.top().v; b = true;
				while (!pqNeg.empty() && pqNeg.top().v == y) {
					cand.push_back(pqNeg.top()); 
					visited[pqNeg.top().id] = 1; pqNeg.pop();
				}
			}
			else {
				int y = pqPos.top().v; b = false;
				while (!pqPos.empty() && pqPos.top().v == y) {
					cand.push_back(pqPos.top());
					visited[pqPos.top().id] = 1; pqPos.pop();
				}
			}

			for (auto &f : cand) {
				for (edge &e : nodes[f.id].edges) {
					if (e.v == f.p && b) {
						ll w = longest - recTime[e.v];
						res[e.id / 2] = w + 1; recTime[f.id] = longest + 1;
					}
					if (e.v == f.p && !b) {
						ll w = f.v - recTime[e.v];
						res[e.id / 2] = w; recTime[f.id] = f.v;
					}
					if (visited[e.v]) { continue; }
					visited[e.v] = true;
					if (v[e.v] < 0) { pqNeg.push(val(v[e.v], e.v, f.id)); }
					else { pqPos.push(val(v[e.v], e.v, f.id)); }
				}
			}
			vis += cand.size(); longest = b ? longest + 1 : cand[0].v;			
		}
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int c, d; cin >> c >> d; graph g(c); 
		v.resize(c); recTime.clear(); recTime.resize(c, 1ll << 40);
		res.clear(); res.resize(d, -1);
		for (int i = 1; i < c; i++) { cin >> v[i]; }
		for (int j = 0; j < d; j++) {
			int u, v; cin >> u >> v;
			u--; v--; g.add_edge(u, v);
		}
		g.bfs(); for (auto &x : res) if (x == -1) x = 1000000;
		cout << "Case #" << t << ": ";
		for (auto &x : res) { cout << x << ' '; } cout << '\n';
	}
	cin.ignore(2); return 0;
}