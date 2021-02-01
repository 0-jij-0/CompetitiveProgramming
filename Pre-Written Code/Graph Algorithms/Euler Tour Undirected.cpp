#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
using namespace std;

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { vector<int> edges; };

//Goes over all edges, not necessarily all vertices
struct graph {
	vector<edge> edges;
	vector<node> nodes;
	int n, m;
	graph(int _n) : n(_n), m(0) { nodes.resize(n); }

	void add_edge(int u, int v) {
		nodes[u].edges.push_back(m);
		nodes[v].edges.push_back(m);
		edges.push_back(edge(u,v)); m++;
	}

	//Start can be any node; if it has to be 0 we should hard code it
	//Since node 0 could have 0 edges and start becomes 1 for ex
	vector<int> euler_undirected() {
		int start = -1, odd_deg = 0;
		for (int i = 0; i < n; ++i) {
			if ((int)nodes[i].edges.size() & 1) { odd_deg++; start = i; }
			else if (!nodes[i].edges.empty() && start == -1) { start = i; }
		}

		//if (odd_deg > 0) { return vector<int>(); } //Euler tour/cycle not possible
		if (odd_deg > 2) { return vector<int>(); }	//Euler path not possible
		vector<bool> used(m, 0);
		vector<int> stack, res, which(n + 1, 0);		//which[v] = index of the edge with endpoint v to check next
		stack.push_back(start);
		while (!stack.empty()) {
			int v = stack.back();
			while (which[v] < (int)nodes[v].edges.size() && used[nodes[v].edges[which[v]]]) { which[v]++; }
			if (which[v] == (int)nodes[v].edges.size()) {
				stack.pop_back(); res.push_back(v);
			}
			else {
				int ed = nodes[v].edges[which[v]];
				int w = (edges[ed].u) == v ? edges[ed].v : edges[ed].u;
				used[ed] = 1; stack.push_back(w);
			}
		}
		if (count(used.begin(), used.end(), false)) { return vector<int>(); }	//Not all edges were reachable
		//reverse(res.begin(), res.end());			//Reverse if we want to make sure the path starts at start (for cycles doesn't matter)
		return move(res);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin.ignore(2); return 0;
}