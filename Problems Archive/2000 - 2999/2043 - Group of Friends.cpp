#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long ll;

ll ans = 0;

struct edge {
	int val; bool special;
	int u, v; edge() {}
	edge(int _u, int _v, int _val, bool _b) :
		u(_u), v(_v), val(_val), special(_b) {}
};

struct node { int val = 0; vector<edge> edges; };

struct Tree {
	vector<node> nodes;
	vector<int> sz;
	int root, n;

	Tree(int _n, int _r = 0) : n(_n), root(_r) { nodes.resize(n); sz.resize(n, 1); }

	void add_edge(int u, int v, int val, bool special) {
		edge e1(u, v, val, special); edge e2(v, u, val, special);
		nodes[u].edges.push_back(e1);
		nodes[v].edges.push_back(e2);
	}

	void centroidDecomposition() {
		vector<bool> dead(n, false);
		CDRec(0, dead);
	}

private:
	int subtreeN;
	int getCentroid(int root, vector<bool>& dead) {
		getSize(root, -1, dead);
		subtreeN = sz[root];
		return findCentroid(root, -1, dead);
	}
	void getSize(int u, int p, vector<bool>& dead) {
		sz[u] = 1;
		for (auto& e : nodes[u].edges) {
			if (e.v == p || dead[e.v]) { continue; }
			getSize(e.v, u, dead);
			sz[u] += sz[e.v];
		}
	}
	int findCentroid(int u, int p, vector<bool>& dead) {
		for (auto &e : nodes[u].edges) {
			if (e.v == p || dead[e.v]) { continue; }
			if (sz[e.v] > subtreeN / 2) { return findCentroid(e.v, u, dead); }
		}
		return u;
	}

	void CDRec(int start, vector<bool>& dead) {
		int c = getCentroid(start, dead);
		dead[c] = true;

		for (auto& e : nodes[c].edges) {
			if (dead[e.v]) { continue; }
			CDRec(e.v, dead);
		}

		vector<pair<int, ll>> startNotSp, startSp, endNotSp, endSp;
		vector<ll> endNotSpV, endSpV;

		unordered_map<int, ll> idxToStartNotSp, idxToStartSp;

		int idx = 0;
		for (auto& e : nodes[c].edges) {
			if (dead[e.v]) { continue; }

			if (nodes[e.v].val >= nodes[e.u].val) {
				auto start = findInc(e.v, c, nodes[e.v].val, e.val, dead, e.special);
				ans += start.second;

				startNotSp.push_back({ e.val, start.first });
				idxToStartNotSp.insert({ e.v, start.first });

				startSp.push_back({ e.val, start.second });
				idxToStartSp.insert({ e.v, start.second });
			}
			if (nodes[e.v].val <= nodes[e.u].val) {
				auto end = findDec(e.v, c, nodes[e.v].val, e.val, dead, e.special);
				ans += end.second;

				endNotSp.push_back({ e.val, end.first });
				endSp.push_back({ e.val, end.second });

				endNotSpV.push_back(e.v); endSpV.push_back(e.v);
			}

			idx++;
		}

		sort(startNotSp.begin(), startNotSp.end());
		sort(startSp.begin(), startSp.end());

		for (int i = 1; i < startSp.size(); i++) { startSp[i].second += startSp[i - 1].second; }
		for (int i = 1; i < startNotSp.size(); i++) { startNotSp[i].second += startNotSp[i - 1].second; }

		//not sp -> sp
		for (int i = 0; i < endNotSp.size(); i++) {
			int curEdgeVal = endNotSp[i].first, v = endNotSpV[i];

			pair<int, ll> ptmp = { curEdgeVal, 0 };
			int idx = lower_bound(startSp.begin(), startSp.end(), ptmp) - startSp.begin();
			if (!startSp.empty() && idx < startSp.size()) {
				ll numMatches = startSp.back().second - (idx ? startSp[idx - 1].second : 0);
				numMatches -= idxToStartSp[v];

				ans += endNotSp[i].second * numMatches;
			}
		}

		//sp -> not sp  && sp -> sp
		for (int i = 0; i < endSp.size(); i++) {
			int curEdgeVal = endSp[i].first, v = endSpV[i];

			pair<int, ll> ptmp = { curEdgeVal, 0 };
			int idx = lower_bound(startNotSp.begin(), startNotSp.end(), ptmp) - startNotSp.begin();
			if (!startNotSp.empty() && idx < startNotSp.size()) {
				ll numMatches = startNotSp.back().second - (idx ? startNotSp[idx - 1].second : 0);
				numMatches -= idxToStartNotSp[v];

				ans += endSp[i].second * numMatches;
			}

			idx = lower_bound(startSp.begin(), startSp.end(), ptmp) - startSp.begin();
			if (!startSp.empty() && idx < startSp.size()) {
				ll numMatches = startSp.back().second - (idx ? startSp[idx - 1].second : 0);
				numMatches -= idxToStartSp[v];

				ans += endSp[i].second * numMatches;
			}
		}

		dead[c] = false;
	}

	pair<ll, ll> findInc(int u, int p, int curNodeVal, int curEdgeVal, vector<bool>& dead, bool special) {
		pair<ll, ll> curAns = { 0,0 };
		if (special) { curAns.second = 1; }
		else { curAns.first = 1; }

		for (auto& e : nodes[u].edges) {
			if (e.v == p || dead[e.v]) { continue; }
			if (e.val < curEdgeVal || nodes[e.v].val < nodes[e.u].val) { continue; }
			auto p = findInc(e.v, u, nodes[e.v].val, e.val, dead, special || e.special);
			curAns.first += p.first; curAns.second += p.second;
		}

		return curAns;
	}

	pair<ll, ll> findDec(int u, int p, int curNodeVal, int curEdgeVal, vector<bool>& dead, bool special) {
		pair<ll, ll> curAns = { 0,0 };
		if (special) { curAns.second = 1; }
		else { curAns.first = 1; }

		for (auto& e : nodes[u].edges) {
			if (e.v == p || dead[e.v]) { continue; }
			if (e.val > curEdgeVal || nodes[e.v].val > nodes[e.u].val) { continue; }
			auto p = findDec(e.v, u, nodes[e.v].val, e.val, dead, e.special);

			if (special) { curAns.second += p.first + p.second; }
			else {
				curAns.first += p.first;
				curAns.second += p.second;
			}
		}

		return curAns;
	}
};

int main() {
	freopen("path.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--) {
		int n; cin >> n; Tree t(n);
		ans = 0;

		for (int i = 0; i < n; i++) { cin >> t.nodes[i].val; }
		for (int i = 0; i < n - 1; i++) {
			int u, v; cin >> u >> v; u--; v--;
			int val, k; cin >> val >> k;
			t.add_edge(u, v, val, k);
		}

		t.centroidDecomposition();
		cout << ans << '\n';
	}
}