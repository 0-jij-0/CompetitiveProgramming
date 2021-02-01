#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

struct node { vector<int> edges; };

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v) {
		nodes[u].edges.push_back(v);
		nodes[v].edges.push_back(u);
	}

	int bfs(vector<int> &v) {
		queue<int> q; vector<bool> visited(n, false);
		for (auto &x : v) {
			if (visited[x]) { continue; }
			visited[x] = true; q.push(x);
		}
		int res = 0;
		while (!q.empty()) {
			int f = q.front(); q.pop(); res = f;
			node&n = nodes[f];
			for (auto &x : n.edges) {
				if (visited[x] == false) {
					q.push(x); visited[x] = true;
				}
			}
		}
		return res;
	}

};

vector<int> v;

string toBinary(int x, const int &k) {
	string res = "";
	while (x) { res.push_back(x % 2 + '0'); x >>= 1; }
	res.resize(k, '0'); reverse(res.begin(), res.end());
	return move(res);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, k; cin >> n >> k; 
	int N = 1 << k; graph g(N);
	for (int i = 0; i < N; i++) {
		int mask = 1;
		while (mask < N) {
			if (i > (i ^ mask)) { mask <<= 1; continue; }
			g.add_edge(i, i ^ mask); mask <<= 1;
		}
	}
	for (int i = 0; i < n; i++) {
		int x = 0; char c;
		for (int j = 0; j < k; j++) {
			cin >> c; x <<= 1; x += c - '0';
		}
		v.push_back(x);
	}
	cout << toBinary(g.bfs(v), k) << endl;
	cin.ignore(2); return 0;
}