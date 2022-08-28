#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
using namespace std;

struct Edge {
	int u, v; Edge() {}
	Edge(int _u, int _v) :
		u(_u), v(_v) {}
};

//Goes over all edges, not necessarily all vertices
struct Graph {
	vector<Edge> edges; int m = 0;
	vector<vector<int>> nodes; int n;

	Graph(int _n) : n(_n), nodes(_n) {}

	void addEdge(int u, int v) {
		nodes[u].push_back(m);
		nodes[v].push_back(m++);
		edges.emplace_back(u, v);
	}

	//Start can be any node; if it has to be 0 we should hard code it
	//Since node 0 could have 0 edges and start becomes 1 for ex
	vector<int> eulerTourUndirected() {
		int start = -1, odd_deg = 0;
		for (int i = 0; i < n; ++i) {
			if ((int)nodes[i].size() & 1) { odd_deg++; start = i; }
			else if (!nodes[i].empty() && start == -1) { start = i; }
		}

		//if (odd_deg > 0) { return vector<int>(); } //Euler tour/cycle not possible
		if (odd_deg > 2) { return vector<int>(); }	//Euler path not possible
		vector<bool> used(m, 0);
		vector<int> stack, res, which(n + 1, 0);		//which[v] = index of the edge with endpoint v to check next
		stack.push_back(start);
		while (!stack.empty()) {
			int v = stack.back();
			while (which[v] < (int)nodes[v].size() && used[nodes[v][which[v]]]) { which[v]++; }
			if (which[v] == (int)nodes[v].size()) {
				stack.pop_back(); res.push_back(v);
			}
			else {
				int ed = nodes[v][which[v]];
				int w = (edges[ed].u) == v ? edges[ed].v : edges[ed].u;
				used[ed] = 1; stack.push_back(w);
			}
		}
		if (count(used.begin(), used.end(), false)) { return vector<int>(); }	//Not all edges were reachable
		//reverse(res.begin(), res.end());			//Reverse if we want to make sure the path starts at start (for cycles doesn't matter)
		return res;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

}