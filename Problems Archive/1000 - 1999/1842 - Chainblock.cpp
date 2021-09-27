#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct node { 
	vector<int> edges; 
	map<int, int>* m = new map<int, int>(); 
	int incomp = 0;
};

vector<int> F, freq;

map<int, int> *merge(map<int, int> *cur, map<int, int> *other, int &incomp, int iO) {
	map<int, int> *A = (cur->size() >= other->size()) ? cur : other;
	map<int, int> *B = (cur->size() >= other->size()) ? other : cur;
	if (cur->size() < other->size()) { incomp = iO; }

	for (auto& x : *B) {
		if (!A->count(x.first)) { incomp++; }
		(*A)[x.first] += x.second;
		if ((*A)[x.first] == freq[x.first]) { incomp--; }
	}

	B->clear(); return A;
}

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v) {
		nodes[u].edges.emplace_back(v);
		nodes[v].edges.emplace_back(u);
	}

	void dfs(int cur, int p, int& res) {
		for (int& e : nodes[cur].edges) if(e != p) {
			dfs(e, cur, res);
			nodes[cur].m = merge(nodes[cur].m, nodes[e].m, nodes[cur].incomp, nodes[e].incomp);
		}
		res += nodes[cur].incomp == 0;
	}
};

int main() {
	ifstream cin("B.in.txt");
	ofstream cout("B.out.txt");

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int n; cin >> n; graph g(n);
		for (int i = 1; i < n; i++) {
			int a, b; cin >> a >> b;
			g.add_edge(--a, --b);
		}

		F.resize(n); freq.clear(); freq.resize(n, 0);
		for (auto& x : F) { cin >> x; freq[--x]++; }

		for (int i = 0; i < n; i++) {
			g.nodes[i].m->insert({ F[i], 1 });
			g.nodes[i].incomp = freq[F[i]] != 1;
		}

		int res = -1; g.dfs(0, -1, res);
		cout << "Case #" << t << ": " << res << '\n';
	}

	return 0;
}