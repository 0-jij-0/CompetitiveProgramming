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

struct node { int inD = 0, outD = 0; vector<int> edges; };

//Goes over all edges, not necessarily all vertices
struct graph {
	vector<edge> edges;
	vector<node> nodes;
	int n, m;
	graph(int _n) : n(_n), m(0) { nodes.resize(n); }

	void add_edge(int u, int v) {
		nodes[u].edges.push_back(m++);
		nodes[u].outD++; nodes[v].inD++;
		edges.push_back(edge(u, v));
	}

	//Start can be any node; if it has to be 0 we should add a check
	//Since node 0 could have 0 edges and start becomes 1 for ex
	vector<int> euler_directed() {
		int start = -1, oddIn = 0, oddOut = 0;
		for (int i = 0; i < n; ++i) {
			int diff = nodes[i].inD - nodes[i].outD;
			if (abs(diff) > 1) { return vector<int>(); }
			if (diff == -1) { oddOut++; start = i; }
			else if (diff == 1) { oddIn++; }
			else if (diff == 0 && start == -1) { start = i; }
		}

		//if (oddOut || oddIn) { return vector<int>(); }	//No Euler Cycle
		if (oddOut > 1 || oddIn > 1) { return vector<int>(); }	//No Euler Path
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
		reverse(res.begin(), res.end());
		return move(res);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin.ignore(2); return 0;
}