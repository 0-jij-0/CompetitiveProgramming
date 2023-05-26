#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;

vector<string> s; int m;
vector<int> SPS, SPT;

struct Graph {
	vector<vector<int>> nodes; int N;
	Graph(int _n) : N(_n), nodes(_n) {}

	void addEdge(int u, int v) {
		nodes[u].emplace_back(v);
		nodes[v].emplace_back(u);
	}

	vector<int> shortestPathT() {
		vector<int> res(N, INF); res[N - 1] = 0;
		for (int i = N - 2; i >= 0; i--) 
			for (int j = 0; j < m; j++)
				if (s[i][j] == '1' && i + j + 1 < N)
					res[i] = min(res[i], 1 + res[i + j + 1]);
		return res;
	}
	vector<int> shortestPathS() {
		vector<int> res(N, INF); res[0] = 0;
		for (int i = 0; i < N - 1; i++)
			for (int j = 0; j < m; j++)
				if (s[i][j] == '1' && i + j + 1 < N)
					res[i + j + 1] = min(res[i + j + 1], 1 + res[i]);
		return res;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n >> m; Graph G(n); s.resize(n);
	for (auto& x : s) cin >> x;

	SPT = G.shortestPathT(); SPS = G.shortestPathS();
	set<pair<int, int>> jumpNodes;
	vector<vector<int>> toErase(n);

	for (int i = 1; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i - 1][j] == '1' && i + j < n) {
				if (SPS[i - 1] != INF && SPT[i + j] != INF) {
					jumpNodes.insert({ SPS[i - 1] + 1 + SPT[i + j], i + j });
					toErase[i + j].push_back(SPS[i - 1] + 1 + SPT[i + j]);
				}
			}
		}
		for (auto& x : toErase[i]) jumpNodes.erase({ x, i });
		cout << (jumpNodes.empty() ? -1 : jumpNodes.begin()->first) << ' ';
	}
	cout << '\n';
}