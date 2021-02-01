#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>
using namespace std;

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	vector<int> in, out;
	graph(int _n) : n(_n), nodes(_n), in(_n, 0), out(_n, 0) {}

	void add_edge(int u, int v) {
		in[v]++; out[u]++;
		nodes[u].edges.emplace_back(u, v);
	}

	vector<int> bfs() {
		vector<int> res(n + 1, 0); queue<pair<int, int>> q;
		for (int i = 0; i < n; i++) if (!in[i]) q.push({ i, 1 });
		int curRound = 1, total = 0;
		while (!q.empty()) {
			int cur = q.front().first, round = q.front().second; q.pop();
			if (round != curRound) { res[curRound] = -total; total = 0; curRound = round; }
			total++;
			for (edge& e : nodes[cur].edges) {
				if (e.v == cur) { continue; }
				in[e.v]--; if (!in[e.v])
					q.push({ e.v, curRound + 1 });
			}
		}
		res[curRound] = -total;
		partial_sum(res.begin(), res.end(), res.begin());
		for (auto& x : res) x += n;	return move(res);
	}

};

bool comp(int i, int j) { return j < i; }

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; graph g(n);
	for (int i = 0; i < n; i++) {
		int s; cin >> s; s--;
		g.add_edge(i, s);
	}
	vector<int> res = g.bfs();
	//for (auto& x : res) cout << x << ' '; cout << '\n';
	int q; cin >> q; while (q--) {
		int k; cin >> k;
		if (!binary_search(res.begin(), res.end(), k, comp)) { cout << -1 << '\n'; continue; }
		cout << lower_bound(res.begin(), res.end(), k, comp) - res.begin() << endl;
	}
	cin.ignore(2); return 0;
}