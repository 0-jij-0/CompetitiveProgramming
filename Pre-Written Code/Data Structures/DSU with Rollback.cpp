#include <bits/stdc++.h>
using namespace std;

struct DSUwithRollback {
	int n, numOfComponents;
	vector<int> rank, parent, checkpoint;
	vector<pair<int, int>> parentHistory, rankHistory;

	DSUwithRollback(int _n) : n(_n), numOfComponents(_n), rank(_n, 1), parent(_n)	{
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
		while (rankHistory.size() > checkpoint.back()) {
			parent[parentHistory.back().first] = parentHistory.back().second;
			rank[rankHistory.back().first] = rankHistory.back().second;
			parentHistory.pop_back(); rankHistory.pop_back();
			numOfComponents++;
		}
		checkpoint.pop_back();
	}
};

enum struct QueryType { ADD_EDGE, NUM_OF_COMPONENTS, ARE_CONNECTED } type;

struct Query {
	QueryType type; int L, R, u, v;
	Query(QueryType _type, int _L, int _R, int _u = 0, int _v = 0) :
		type(_type), L(_L), R(_R), u(_u), v(_v) {}
};

struct DynamicGraph {
	map<pair<int, int>, int> activeEdges;
	vector<Query> edgeQueries, answerQueries;
	DSUwithRollback DSU;
	int TIME = 0, n;

	DynamicGraph(int _n) : DSU(_n), n(_n) {}

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
		edgeQueries.emplace_back(QueryType::ADD_EDGE, activeEdges[{u, v}], ++TIME, u, v);
		activeEdges.erase({ u, v });
	}

	void getNumOfComponents() {
		++TIME; answerQueries.emplace_back(QueryType::NUM_OF_COMPONENTS, TIME, TIME);
	}

	void checkConnectedness(int u, int v) {
		++TIME; answerQueries.emplace_back(QueryType::ARE_CONNECTED, TIME, TIME, u, v);
	}

	vector<int> answerQueries() {
		++TIME; for (auto& e : activeEdges)
			edgeQueries.emplace_back(QueryType::ADD_EDGE, e.second, TIME, e.first.first, e.first.second);

		vector<int> res;
		processQueries(0, TIME, edgeQueries, answerQueries, res);
		return res;
	}

	void processQueries(int L, int R, vector<Query>& curEdgeQueries, vector<Query> &curAnswerQueries, vector<int>& res) {
		if (curAnswerQueries.empty()) return;

		DSU.setCheckpoint(); for (auto& query : curEdgeQueries)
			if (query.L <= L && query.R >= R) DSU.merge(query.u, query.v);

		if (L == R) {
			if(curAnswerQueries.front().type == QueryType::NUM_OF_COMPONENTS) res.push_back(DSU.numOfComponents);
			else res.push_back(DSU.areConnected(curAnswerQueries.front().u, curAnswerQueries.front().v));
			DSU.rollback(); return;
		}
		
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


}