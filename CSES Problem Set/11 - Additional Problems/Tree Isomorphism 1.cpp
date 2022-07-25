#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Tree {
	vector<vector<int>> nodes; int n;

	Tree(int _n) : nodes(_n), n(_n) {}

	void addEdge(int u, int v) {
		nodes[u].emplace_back(v);
		nodes[v].emplace_back(u);
	}

	vector<vector<int>> levelsBFS(int u) {
		vector<int> levels(n, -1); levels[u] = 0;
		queue<int> Q; Q.push(u); int last = u;
		vector<vector<int>> res(n);

		while (!Q.empty()) {
			int cur = Q.front(); Q.pop();
			res[levels[cur]].push_back(cur);
			last = cur;

			for (auto& e : nodes[cur]) if (levels[e] == -1) {
				levels[e] = 1 + levels[cur]; Q.push(e);
			}
		}

		res.resize(1 + levels[last]);
		return res;
	}

	static bool compareNames(const vector<int>& A, const vector<int>& B) {
		if (A.size() != B.size()) return A.size() < B.size();
		for (int i = 0; i < (int)A.size(); i++)
			if (A[i] != B[i]) return A[i] < B[i];
		return false;
	}

	static bool eqNames(vector<int>& A, vector<int>& B) {
		if (A.size() != B.size()) return false;
		for (int i = 0; i < (int)A.size(); i++)
			if (A[i] != B[i]) return false;
		return true;
	}

	bool processLevel(Tree& rhs, vector<int>& curL, vector<int>& rhsL, vector<int>& curCannonicalNames, vector<int>& rhsCannonicalNames) {
		int M = (int)curL.size(); if (M != (int)rhsL.size()) return false;
		vector<vector<int>> curName(M), rhsName(M), comp;

		for (int i = 0; i < M; i++) {
			for (auto& e : nodes[curL[i]]) if (curCannonicalNames[e] != -1)
				curName[i].push_back(curCannonicalNames[e]);
			sort(curName[i].begin(), curName[i].end());

			for (auto& e : rhs.nodes[rhsL[i]]) if (rhsCannonicalNames[e] != -2)
				rhsName[i].push_back(rhsCannonicalNames[e]);
			sort(rhsName[i].begin(), rhsName[i].end());

			comp.emplace_back(curName[i]);
			comp.emplace_back(rhsName[i]);
		}

		sort(comp.begin(), comp.end(), compareNames);
		comp.erase(unique(comp.begin(), comp.end(), eqNames), comp.end());

		for (int i = 0; i < M; i++) {
			auto curI = lower_bound(comp.begin(), comp.end(), curName[i], compareNames);
			auto rhsI = lower_bound(comp.begin(), comp.end(), rhsName[i], compareNames);
			curCannonicalNames[curL[i]] = curI - comp.begin();
			rhsCannonicalNames[rhsL[i]] = rhsI - comp.begin();
		}

		return true;
	}

	bool rootedIsomorphismTest(Tree& rhs, int root1, int root2) {
		vector<vector<int>> curLevels = levelsBFS(root1);
		vector<vector<int>> rhsLevels = rhs.levelsBFS(root2);
		if (curLevels.size() != rhsLevels.size()) return false;

		int L = (int)curLevels.size();
		vector<int> curCannonicalNames(n, -1), rhsCannonicalNames(n, -2);

		bool ok = true; for (int i = L - 1; i >= 0 && ok; i--)
			ok = ok && processLevel(rhs, curLevels[i], rhsLevels[i], curCannonicalNames, rhsCannonicalNames);

		return ok && (curCannonicalNames[root1] == rhsCannonicalNames[root2]);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; Tree T1(n), T2(n);
		for (int i = 1; i < n; i++) {
			int u, v; cin >> u >> v;
			T1.addEdge(--u, --v);
		}
		for (int i = 1; i < n; i++) {
			int u, v; cin >> u >> v;
			T2.addEdge(--u, --v);
		}

		cout << (T1.rootedIsomorphismTest(T2, 0, 0) ? "YES" : "NO") << '\n';
	}
}