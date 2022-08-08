#include <iostream>
#include <vector>
#include <numeric>
#include <map>
using namespace std;

struct PersistentDSU {
	int n, numOfComponents;
	vector<int> rank, parent, checkpoint;
	vector<pair<int, int>> parentHistory, rankHistory;

	PersistentDSU(int _n) : n(_n), numOfComponents(_n), rank(_n, 1), parent(_n) {
		iota(parent.begin(), parent.end(), 0);
	}

	int find(int u) { while (u != parent[u]) u = parent[u]; return u; }
	int size(int u) { return rank[find(u)]; }
	bool areConnected(int u, int v) { return find(u) == find(v); }

	bool merge(int u, int v) {
		if ((u = find(u)) == (v = find(v))) return false;
		if (rank[u] < rank[v]) { swap(u, v); }
		parentHistory.emplace_back(v, parent[v]);
		rankHistory.emplace_back(u, rank[u]);
		rank[u] += rank[v];	parent[v] = u;
		numOfComponents--; return true;
	}

	void setCheckpoint() { checkpoint.push_back(rankHistory.size()); }

	void rollback() {
		while ((int)rankHistory.size() > checkpoint.back()) {
			parent[parentHistory.back().first] = parentHistory.back().second;
			rank[rankHistory.back().first] = rankHistory.back().second;
			parentHistory.pop_back(); rankHistory.pop_back();
			numOfComponents++;
		}
		checkpoint.pop_back();
	}
};

struct Query {
	int L, R, u, v;
	Query(int _L, int _R, int _u = 0, int _v = 0) :
		L(_L), R(_R), u(_u), v(_v) {}
};

struct DynamicGraph {
	map<pair<int, int>, int> activeEdges;
	vector<Query> edgeQueries, answerQueries;
	PersistentDSU DSU;
	int TIME = 0;

	DynamicGraph(int _n) : DSU(_n) {}

	void addEdge(int u, int v) {
		if (u > v) swap(u, v);
		activeEdges[{u, v}] = 0;
	}

	void link(int u, int v) {
		if (u > v) swap(u, v);
		activeEdges[{u, v}] = ++TIME;
	}

	void cut(int u, int v) {
		if (u > v) swap(u, v);
		edgeQueries.emplace_back(activeEdges[{u, v}], ++TIME, u, v);
		activeEdges.erase({ u, v });
	}

	void getNumOfComponents() {
		++TIME; answerQueries.emplace_back(TIME, TIME);
	}

	vector<int> getAnswers() {
		++TIME; for (auto& e : activeEdges)
			edgeQueries.emplace_back(e.second, TIME, e.first.first, e.first.second);

		vector<int> res;
		processQueries(0, TIME, edgeQueries, answerQueries, res);
		return res;
	}

	void processQueries(int L, int R, vector<Query>& curEdgeQueries, vector<Query>& curAnswerQueries, vector<int>& res) {
		if (curAnswerQueries.empty()) return;

		DSU.setCheckpoint(); for (auto& query : curEdgeQueries)
			if (query.L <= L && query.R >= R) DSU.merge(query.u, query.v);

		if (L == R) { res.push_back(DSU.numOfComponents); DSU.rollback(); return; }
		
		int M = (L + R) >> 1;
		vector<Query> leftEdgeQueries, rightEdgeQueries, leftAnswerQueries, rightAnswerQueries;
		for (auto& query : curAnswerQueries) (query.L > M ? rightAnswerQueries : leftAnswerQueries).push_back(query);
		for (auto& query : curEdgeQueries) if (query.L > L || query.R < R) {
			if (query.L <= M) leftEdgeQueries.push_back(query);
			if (query.R > M) rightEdgeQueries.push_back(query);
		}

		processQueries(L, M, leftEdgeQueries, leftAnswerQueries, res);
		processQueries(M + 1, R, rightEdgeQueries, rightAnswerQueries, res);
		DSU.rollback();
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m, k; cin >> n >> m >> k; DynamicGraph g(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v; 
		g.addEdge(--u, --v);
	}

	g.getNumOfComponents(); while (k--) {
		int t, u, v; cin >> t >> u >> v; t--;
		t ? g.cut(--u, --v) : g.link(--u, --v);
		g.getNumOfComponents();
	}

	vector<int> res = g.getAnswers();
	for (auto& x : res) cout << x << ' '; cout << '\n';
}