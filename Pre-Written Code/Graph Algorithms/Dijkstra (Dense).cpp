#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
typedef long long ll;

struct edge {
	int u, v; ll w; edge() {}
	edge(int _u, int _v, ll _w) :
		u(_u), v(_v), w(_w) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v, ll w) {
		nodes[u].edges.emplace_back(u, v, w);
		nodes[v].edges.emplace_back(v, u, w);
	}

	void dijkstra(int s, vector<ll> &dist, vector<int> &parent) {
		vector<bool> visited(n, false); dist[s] = 0; int cur = 0;
		for (int i = 0; i < n; i++) {
			for (int i = 0; i < n; i++)
				if (!visited[i] && dist[i] < dist[cur]) { cur = i; }

			visited[cur] = true;
			for (edge &e : nodes[cur].edges)
				if (dist[e.v] > dist[cur] + e.w)
					dist[e.v] = dist[parent[e.v] = cur] + e.w;
		}
	}
	void dijkstraPrintPath(int s, int d, vector<int> &parent) {
		stack<int> S; S.push(d); int cur = d;
		while (parent[cur] != -1) { cur = parent[cur]; S.push(cur); }
		while (!S.empty()) { cout << S.top() << ' '; S.pop(); }
		cout << endl;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin.ignore(2); return 0;
}