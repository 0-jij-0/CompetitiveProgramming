#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

// fast exponentiation modulo mod
ll powe(ll x, ll p) {
	if (p == 0) return 1;
	ll w = powe((x * x) % mod, p / 2);
	if (p & 1) w = (w * x) % mod;
	return w;
}
// modular inverse (mod must be prime)
ll modinv(ll i) { return powe(i, mod - 2); }

vector<ll> ans;

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { 
	int type = -1; ll prob = 1;
	vector<edge> edges;
};

struct tree {
	vector<node> nodes; int n;

	tree(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v) {
		edge e1(u, v); edge e2(v, u);
		nodes[u].edges.push_back(e1);
		nodes[v].edges.push_back(e2);
	}

	void dfs(int u, int p) {
		if (nodes[u].type == 3) { return; }

		ll curAns = 1;
		for (auto& e : nodes[u].edges) {
			if (e.v == p) { continue; }
			dfs(e.v, u);
			if (nodes[u].type == 1) { curAns *= nodes[e.v].prob; curAns %= mod; }
			else if (nodes[u].type == 2) {
				ll ccc = 1 - nodes[e.v].prob + mod; ccc %= mod;
				curAns *= ccc; curAns %= mod;
			}
		}

		if (nodes[u].type == 2) { curAns = 1 - curAns + mod; curAns %= mod; }
		nodes[u].prob = curAns;
	}

	void dfs2(int u, int p) {
		ans[u] = nodes[u].prob;

		int m = nodes[u].edges.size();
		vector<ll> prefP(m), sufP(m);
		vector<ll> prefPM(m), sufPM(m);
		prefP[0] = nodes[nodes[u].edges[0].v].prob;
		prefPM[0] = 1 - prefP[0] + mod; prefPM[0] %= mod;
		for (int i = 1; i < m; i++) {
			ll curP = nodes[nodes[u].edges[i].v].prob;
			prefP[i] = prefP[i - 1] * curP; prefP[i] %= mod;
			prefPM[i] = prefPM[i - 1] * ((1 - curP + mod) % mod); prefPM[i] %= mod;
		}

		sufP[m - 1] = nodes[nodes[u].edges[m - 1].v].prob;
		sufPM[m - 1] = 1 - sufP[m - 1] + mod; sufPM[m - 1] %= mod;
		for (int i = m - 2; i >= 0; i--) {
			ll curP = nodes[nodes[u].edges[i].v].prob;
			sufP[i] = sufP[i + 1] * curP; sufP[i] %= mod;
			sufPM[i] = sufPM[i + 1] * ((1 - curP + mod) % mod); sufPM[i] %= mod;
		}

		int ii = -1;
		for (auto& e : nodes[u].edges) {
			ii++;
			if (e.v == p) { continue; }
			if (nodes[e.v].type == 3) { continue; }

			ll prevU = nodes[u].prob, prevV = nodes[e.v].prob;
			if (nodes[u].type == 1) {
				ll curL = (ii ? prefP[ii - 1] : 1);
				ll curR = (ii < m - 1 ? sufP[ii + 1] : 1);
				nodes[u].prob = curL * curR; nodes[u].prob %= mod;
			}
			else if (nodes[u].type == 2) {
				ll curL = (ii ? prefPM[ii - 1] : 1);
				ll curR = (ii < m - 1 ? sufPM[ii + 1] : 1);
				nodes[u].prob = curL * curR; nodes[u].prob %= mod;
				nodes[u].prob = 1 - nodes[u].prob + mod; nodes[u].prob %= mod;
			}

			if (nodes[e.v].type == 1) { nodes[e.v].prob *= nodes[u].prob; nodes[e.v].prob %= mod; }
			else if (nodes[e.v].type == 2) {
				nodes[e.v].prob = -nodes[e.v].prob + 1 + mod; nodes[e.v].prob %= mod;
				ll ccc = 1 - nodes[u].prob + mod; ccc %= mod;
				nodes[e.v].prob *= ccc; nodes[e.v].prob %= mod;
				nodes[e.v].prob = 1 - nodes[e.v].prob + mod; nodes[e.v].prob %= mod;
			}

			dfs2(e.v, u);
			nodes[u].prob = prevU;
			nodes[e.v].prob = prevV;
		}
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("gates.in", "r", stdin);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		ans.clear(); ans.resize(n);
		tree tr(n);
		for (int i = 0; i < n - 1; i++) {
			int u, v; cin >> u >> v; u--; v--;
			tr.add_edge(u, v);
		}

		for (int i = 0; i < n; i++) {
			int curT; cin >> curT;
			tr.nodes[i].type = curT;
			if (curT == 3) {
				ll p; cin >> p;
				tr.nodes[i].prob = (p * modinv(1000000)) % mod;
				ans[i] = tr.nodes[i].prob;
				ans[i] += mod; ans[i] %= mod;
			}
		}

		if (n == 1) { cout << ans[0] << '\n'; continue; }
		if (n == 2) { cout << ans[0] << '\n' << ans[1] << '\n'; continue; }

		int root = 0;
		for (int i = 0; i < n; i++) {
			if (tr.nodes[i].type != 3) { root = i; break; }
		}

		tr.dfs(root, -1);
		tr.dfs2(root, -1);

		for (int i = 0; i < n; i++) { cout << ans[i] << '\n'; }
	}
}