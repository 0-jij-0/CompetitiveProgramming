#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;
const ll inf = (ll)1e11;

vector<ll> bpf;
int spf[1000009];

void buildSieve() {
	vector<int> primes; spf[0] = spf[1] = 1;
	for (int i = 2; i < 1000009; i++) {
		if (spf[i] == 0) { primes.push_back(i);	spf[i] = i; }
		for (int j = 0; j < int(primes.size()) &&
			primes[j] <= spf[i] && i * primes[j] < 1000009; j++)
			spf[i * primes[j]] = primes[j];
	}
}

vector<int> factorize(int x) {
	vector<int> res;
	while (x != 1) {
		int d = spf[x]; res.push_back(d);
		while (x % d == 0) { x /= d; }
	}
	return move(res);
}

struct edge {
	int u, v, w, id; edge() {}
	edge(int _u, int _v, int _w, int _id) :
		u(_u), v(_v), w(_w), id(_id) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n = 0;
	vector<edge> edges; int m = 0;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v, int w) {
		edge e1(u, v, w, m), e2(v, u, w, m);
		nodes[u].edges.push_back(e1);
		nodes[v].edges.push_back(e2);
		edges.push_back(e1); m++;
	}

	ll dijkstra(int s, int k, int t) {
		vector<vector<ll>> dist(n, vector<ll>(k + 1, inf));
		priority_queue<pair<pair<ll, int>, int>, vector<pair<pair<ll, int>, int>>, greater<pair<pair<ll, int>, int>>> pq;
		dist[s][0] = 0;	pq.push({ {0, 0}, s });

		while (!pq.empty()) {
			pair<pair<ll, int>, int> cur = pq.top(); pq.pop();
			int curID = cur.second; int curK = cur.first.second;
			if (dist[curID][curK] < cur.first.first) { continue; }

			for (auto &e : nodes[curID].edges) {
				if (dist[e.v][curK] > dist[curID][curK] + e.w) {
					dist[e.v][curK] = dist[curID][curK] + e.w;
					pq.push({{ dist[e.v][curK], curK }, e.v});
				}
				if (curK == k || bpf[e.id] >= e.w) { continue; }
				if (dist[e.v][curK + 1] > dist[curID][curK] + bpf[e.id]) {
					dist[e.v][curK + 1] = dist[curID][curK] + bpf[e.id];
					pq.push({ { dist[e.v][curK + 1],  curK + 1}, e.v});
				}
			}
		}
		return *min_element(dist[t].begin(), dist[t].end());
	}
};

void fill_bpf(const graph &g) {
	bpf.clear(); bpf.resize(g.m);
	for (auto &e : g.edges) {
		vector<int> pf = factorize(e.w);
		int res = 1000 * 1000 * 1000;
		for (int &y : pf)
			res = min(res, (e.w / y) + (2 * y));
		bpf[e.id] = res;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T; buildSieve();
	while (T--) {
		int n, m, k; cin >> n >> m >> k;
		graph g(n);
		for (int i = 0; i < m; i++) {
			int u, v, w; cin >> u >> v >> w; 
			u--; v--; g.add_edge(u, v, w);
		}
		fill_bpf(g); 
		int s, e; cin >> s >> e; s--; e--;
		ll res = g.dijkstra(s, k, e);
		cout << (res >= inf ? -1 : res) << '\n';
	}
	cin.ignore(2); return 0;
}