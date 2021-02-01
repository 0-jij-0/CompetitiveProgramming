#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>
using namespace std;
typedef long long ll;
ll INF = 1ll << 40;

struct edge {
	int u, v, id, dual; edge() {}
	edge(int _u, int _v, int _id, int _d) :
		u(_u), v(_v), id(_id), dual(_id + _d) {}
};

struct node { vector<int> edges; };

struct graph {
	vector<node> nodes; int n;
	vector<edge> edges;
	vector<ll> capacity;
	vector<int> parent;

	graph(int _n) : n(_n), nodes(_n), parent(_n) {}

	void add_edge(int u, int v, ll c) {
		nodes[u].edges.emplace_back(capacity.size());
		nodes[v].edges.emplace_back(capacity.size() + 1);
		edges.emplace_back(u, v, capacity.size(), 1);
		edges.emplace_back(v, u, capacity.size() + 1, -1);
		capacity.push_back(c); capacity.push_back(0); //Change if undirected
	}

	ll maxflow(int s, int t, ll prevFlow = 0) {
		ll flow = prevFlow, new_flow = maxFlowBFS(s, t, parent);

		while (new_flow) {
			flow += new_flow; int cur = t;
			while (cur != s) {
				edge &e = edges[parent[cur]];
				capacity[e.id] -= new_flow;
				capacity[e.dual] += new_flow;
				cur = e.u;
			}
			new_flow = maxFlowBFS(s, t, parent);
		}
		return flow;
	}

	ll maxFlowBFS(const int &s, const int &t, vector<int> &parent) {
		fill(parent.begin(), parent.end(), -1); parent[s] = -2;
		queue<pair<int, ll>> q; q.push({ s, INF });

		while (!q.empty()) {
			int cur = q.front().first; ll flow = q.front().second; q.pop();
			for (auto &e : nodes[cur].edges) {
				int next = edges[e].v, id = edges[e].id;
				if (parent[next] == -1 && capacity[id]) {
					parent[next] = e;
					ll new_flow = min(flow, capacity[id]);
					if (next == t) { return new_flow; }
					q.push({ next, new_flow });
				}
			}
		}
		return 0ll;
	}
};

int strToTime(string &s) {
	string h = s.substr(0, 2), m = s.substr(2, 2);
	return stoi(h) * 60 + stoi(m);
}

struct flight {
	string src, dst; int cap, dep, arr; flight() {}
	flight(string &s, string &d, int &c, string &de, string &ar) :
		src(s), dst(d), cap(c), dep(strToTime(de)), arr(strToTime(ar)) {}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (true) {

		//INPUT
		int n; cin >> n; if (cin.fail()) { break; }
		vector<flight> flights;
		string src, dst; cin >> src >> dst;
		string tim; cin >> tim; int t = strToTime(tim);
		int m; cin >> m; for (int i = 0; i < m; i++) {
			string s, d, de, ar; int c;	
			cin >> s >> d >> c >> de >> ar;
			flights.emplace_back(s, d, c, de, ar);
		}

		graph g(2 * m + 2); int source = g.n - 2, sink = g.n - 1;
		for (int i = 0; i < m; i++) {
			g.add_edge(i << 1, i << 1 | 1, flights[i].cap); //FLIGHT EDGE
			if (flights[i].src == src) g.add_edge(source, i << 1, INF); //SOURCE EDGE
			if (flights[i].dst == dst && flights[i].arr <= t) g.add_edge(i << 1 | 1, sink, INF); //SINK EDGE
			for (int j = 0; j < m; j++) if (i != j)
				if (flights[i].dst == flights[j].src && flights[j].dep - flights[i].arr >= 30)
					g.add_edge(i << 1 | 1, j << 1, INF); //WAITING EDGE
		}
		cout << g.maxflow(source, sink) << '\n';
	}

	cin.ignore(2); return 0;
}