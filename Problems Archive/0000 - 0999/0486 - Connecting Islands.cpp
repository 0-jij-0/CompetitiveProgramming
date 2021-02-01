#include <iostream>
#include <vector>
using namespace std;

struct edge {
	int u, v, w; edge() {}
	edge(int _u, int _v, int _w = 0) :
		u(_u), v(_v), w(_w) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<edge> edges;
	vector<node> nodes;
	vector<vector<int>> D;
	int n;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v, int w = 0) {
		edge e1(u, v, w), e2(v, u, w);
		nodes[u].edges.push_back(e1);
		nodes[v].edges.push_back(e2);
		edges.push_back(e1);
	}

	void allPairsShortestPath() {
		int n = nodes.size(), max = 50;	//Change max to be bigger than any possible output
		D.resize(n); for (int i = 0; i < n; i++) { D[i].resize(n, max); D[i][i] = 0; }

		for (auto &x : nodes)
			for (auto &y : x.edges)
				D[y.u][y.v] = y.w;

		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (D[i][k] + D[k][j] < D[i][j])
						D[i][j] = D[i][k] + D[k][j];
	}
};

vector<vector<char>> v1, v2;
vector<vector<int>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n1; cin >> n1;
	v1.resize(n1, vector<char>(n1));
	for (auto &x : v1)
		for (auto &y : x)
			cin >> y;

	int n2; cin >> n2;
	v2.resize(n2, vector<char>(n2));
	for (auto &x : v2)
		for (auto &y : x)
			cin >> y;

	graph g(n1 + n2);
	for (int i = 0; i < n1; i++)
		for (int j = i + 1; j < n1; j++)
			if (v1[i][j] != 'x')
				g.add_edge(i, j, v1[i][j] - '0');

	for (int i = 0; i < n2; i++)
		for (int j = i + 1; j < n2; j++)
			if (v2[i][j] != 'x')
				g.add_edge(i + n1, j + n1, v2[i][j] - '0');

	g.allPairsShortestPath();
	v.resize(n1 + n2, vector<int>(n1 + n2));
	
	for(int i = 0; i < (int)g.D.size(); i++)
		for (int j = 0; j < (int)g.D.size(); j++)
			v[i][j] = g.D[i][j] != 0;

	g.edges.clear(); g.D.clear();

	for (int i = 0; i < n1 + n2; i++)
		for (int j = i + 1; j < n1 + n2; j++)
				g.add_edge(i, j, v[i][j]);

	g.allPairsShortestPath();

	for (int i = 0; i < n1; i++)
		for (int j = i + 1; j < n1; j++)
			if (v1[i][j] == 'x') { continue; }
			else if (v1[i][j] - '0' != (g.D[i][j] != 0)) {
				cout << "NO" << endl; cin.ignore(2); return 0;
			}

	for (int i = 0; i < n2; i++)
		for (int j = i + 1; j < n2; j++)
			if (v2[i][j] == 'x') { continue; }
			else if (v2[i][j] - '0' != (g.D[i + n1][j + n1] != 0)) {
				cout << "NO" << endl; cin.ignore(2); return 0;
			}

	cout << "YES" << endl;
	for (auto &x : v) {
		for (auto &y : x) { cout << y; }
		cout << endl;
	}

	cin.ignore(2); return 0;
}