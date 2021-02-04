#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
using namespace std;

struct edge {
	int u, v, w; edge() {}
	edge(int _u, int _v, int _w) :
		u(_u), v(_v), w(_w) {}

	bool operator ==(edge& o) {
		return (o.u == u && o.v == v && o.w == w);
	}
};

struct node { 
	bool artPt = false; vector<int> edges;
	node() {}
	node(bool b) :artPt(b) {}
};

struct graph {
	vector<node> nodes; int n;
	vector<edge> edges;
	graph(int _n) : n(_n) { nodes.resize(n); }

	int add_node(bool artPt = false) {
		nodes.push_back(node(artPt));
		n++; return n - 1;
	}

	//Resizes the vectors other than nodes after adding nodes using add_node (when building the block tree)
	//Do NOT resize nodes as it resets the edges
	void resizeVectors() { }

	void add_edge(int u, int v, int w = 0) {
		nodes[u].edges.emplace_back(edges.size());
		edges.emplace_back(u, v, w);
		nodes[v].edges.emplace_back(edges.size());
		edges.emplace_back(v, u, w);
	}

	//tin[u] = discovery time of u
	//low[u] = lowest discovery time of a reachable node
	void artPointDFS(int cur, int p, vector<int>& low, vector<int>& tin,
		vector<int>& treeIdx, int& timer, int cnt, stack<edge>& S, vector<vector<edge>>& comp) {
		treeIdx[cur] = cnt; tin[cur] = low[cur] = timer++; int c = 0;
		for (auto& x : nodes[cur].edges) {
			edge& e = edges[x];	if (e.v == p) { continue; }
			if (treeIdx[e.v] == -1 || tin[e.u] > tin[e.v]) { S.push(e); }
			if (treeIdx[e.v] != -1) { low[cur] = min(low[cur], tin[e.v]); continue; }

			artPointDFS(e.v, cur, low, tin, treeIdx, timer, cnt, S, comp);
			low[cur] = min(low[cur], low[e.v]); c++;
			if (p != -1 && low[e.v] >= tin[cur]) { nodes[cur].artPt = true; }
			if (low[e.v] >= tin[cur]) {
				comp.push_back(vector<edge>());
				while (true) {
					edge& curE = S.top(); S.pop();
					comp.back().push_back(curE);
					if (curE == e) { break; }
				}
			}
		}
		if (p == -1 && c > 1) { nodes[cur].artPt = true; }
	}

	//Finds the biconnected components in the component of u
	vector<vector<edge>> findBiComponents(int u, int cnt, vector<int>& treeIdx) {
		int timer = 0; vector<int> low(n, -1), tin(n, -1);
		stack<edge> S; vector<vector<edge>> comp;
		artPointDFS(u, -1, low, tin, treeIdx, timer, cnt, S, comp);
		return move(comp);
	}

	//Builds a forest with 2 types of nodes: compressed bi-components and articulation points
	//Each tree corresponds to one component in the graph
	//treeIdx[i] is the tree idx of node i
	//comp[i] is the idx of the biconnected component/art point that contains i in the block tree treeIdx[i]
	vector<graph> buildBlockTrees(vector<int>& treeIdx, vector<int>& comp) {
		treeIdx.clear(); treeIdx.resize(n, -1);
		comp.clear(); comp.resize(n, -1);
		vector<graph> forest; int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (treeIdx[i] != -1) { continue; }
			vector<vector<edge>> edges = findBiComponents(i, cnt++, treeIdx);
			graph curG(0);
			for (auto& biComp : edges) {
				int id = curG.add_node();
				for (auto& e : biComp) {
					for (auto& x : { e.u, e.v }) {
						if (nodes[x].artPt) {
							if (comp[x] == -1) { comp[x] = curG.add_node(true); }
							curG.add_edge(id, comp[x]);	 //Might get multi-edges if multiple nodes in a comp are connected to the same art pt (not a prob with LCA)
						}
						else { comp[x] = id; }
					}
				}
			}
			if (edges.empty()) { comp[i] = curG.add_node(); }  //Isolated vertex
			curG.resizeVectors();
			forest.emplace_back(curG);
		}
		return move(forest);
	}
};

//When working with vertices, don't forget to use comp[u] instead of u
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);


}