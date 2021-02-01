#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll inf = 1ll << 60;

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { ll a; int b, c; vector<int> edges; };

vector<node> tree;

void add_edge(int u, int v) {
	tree[u].edges.push_back(v);
	tree[v].edges.push_back(u);
}

ll dfs(int cur, int p, int &zo, int &oz) {
	if (tree[cur].b != tree[cur].c) { (tree[cur].b ? oz : zo)++; }
	ll res = 0;
	for (int &e : tree[cur].edges) {
		if (e == p) { continue; }
		int ZO = 0, OZ = 0;
		tree[e].a = min(tree[e].a, tree[cur].a);
		res += dfs(e, cur, ZO, OZ);
		zo += ZO; oz += OZ;
	}
	int d = min(zo, oz); res += 2 * d * tree[cur].a; 
	oz -= d; zo -= d; return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; tree.resize(n);
	for (auto &x : tree) { cin >> x.a >> x.b >> x.c; }
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		u--; v--; add_edge(u, v);
	}

	int zo = 0, oz = 0; ll res = dfs(0, -1, zo, oz);
	cout << (zo + oz ? -1 : res) << '\n';
	cin.ignore(2); return 0;
}