#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <string>
#include <unordered_set>
#include <climits>
using namespace std;
 
struct node { unordered_set<int> edges; };
 
struct graph {
	vector<node> nodes;
	int n;
 
	graph(int _n) : n(_n) { nodes.resize(n); }
 
	void add_edge(int u, int v) {
		nodes[u].edges.insert(v);
		nodes[v].edges.insert(u);
	}
 
	bool dfs(int u, int p, vector<bool> &visited) {
		visited[u] = 1;
		for (auto &v : nodes[u].edges) {
			if (v == p) { continue; }
			if (visited[v]) { return true; }
			bool b = dfs(v, u, visited);
			if (b) { return true; }
		}
		return false;
	}
 
	bool containsCycle() {
		vector<bool> visited(n, 0);
		for (int i = 0; i < n; i++) {
			if (!visited[i]) { 
				bool b = dfs(i, -1, visited); 
				if (b) { return true; }
			}
		}
		return false;
	}
};
 
void makeUnique(vector<int> &v) {
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
 
	int K; cin >> K;
	vector<pair<int, int>> edges3, edges2;
	vector<int> nodes3, nodes2;
	for (int i = 0; i < K; i++) {
		int x1, y1, z1, x2, y2, z2; cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
		int n13 = x1 * 1000000 + y1 * 1000 + z1, n12 = x1 * 1000 + y1;
		int n23 = x2 * 1000000 + y2 * 1000 + z2, n22 = x2 * 1000 + y2;
		nodes3.push_back(n13); nodes3.push_back(n23); edges3.push_back({ n13, n23 });
		nodes2.push_back(n12); nodes2.push_back(n22); edges2.push_back({ n12, n22 });
	}
 
	makeUnique(nodes2); makeUnique(nodes3);
 
	graph g2(nodes2.size()), g3(nodes3.size());
	for (auto &p : edges3) {
		int u = lower_bound(nodes3.begin(), nodes3.end(), p.first) - nodes3.begin();
		int v = lower_bound(nodes3.begin(), nodes3.end(), p.second) - nodes3.begin();
		if (u != v)g3.add_edge(u, v);
	}
 
	for (auto &p : edges2) {
		int u = lower_bound(nodes2.begin(), nodes2.end(), p.first) - nodes2.begin();
		int v = lower_bound(nodes2.begin(), nodes2.end(), p.second) - nodes2.begin();
		if (u != v)g2.add_edge(u, v);
	}
 
	if (g3.containsCycle()) { cout << "True closed chains\n"; }
	else { cout << "No true closed chains\n"; }
 
	if (g2.containsCycle()) { cout << "Floor closed chains\n"; }
	else { cout << "No floor closed chains\n"; }
}