#include <fstream>
#include <vector>
#include <queue>
using namespace std;

vector<string> S; int R, C;

struct Graph {
	vector<vector<int>> nodes; 
	vector<int> deg; int n;
	Graph(int _n) : nodes(_n), deg(_n), n(_n) {}

	void addEdge(int u, int v) {
		nodes[u].emplace_back(v); deg[u]++;
		nodes[v].emplace_back(u); deg[v]++;
	}

	bool bfs() {
		queue<int> Q; vector<bool> vis(n, false);
		
		for (int i = 0; i < n; i++) if(S[i / C][i % C] != '#')
			if (deg[i] < 2) { vis[i] = true; Q.push(i); }
		

		while (!Q.empty()) {
			int cur = Q.front(); Q.pop();
			if (S[cur / C][cur % C] == '^') { return false; }
			for (auto& e : nodes[cur]) if(!vis[e]) 
				if (--deg[e] < 2) { vis[e] = true; Q.push(e); }
		}

		for (int i = 0; i < n; i++) if (!vis[i])
			if (S[i / C][i % C] == '.') S[i / C][i % C] = '^';

		return true;
	}
};

int main() {
	ifstream cin("second_second_friend_input.txt");
	ofstream cout("second_second_friend_output.txt");

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> R >> C; Graph G(R * C); S.resize(R);
		for (auto& x : S) cin >> x;

		for(int i = 0; i < R; i++)
			for (int j = 0; j < C; j++) if(S[i][j] != '#') {
				if (i && S[i - 1][j] != '#') G.addEdge(i * C + j, (i - 1) * C + j);
				if (j && S[i][j - 1] != '#') G.addEdge(i * C + j, i * C + j - 1);
			}

		cout << "Case #" << t << ": ";
		if (!G.bfs()) { cout << "Impossible\n"; continue; }
		cout << "Possible\n"; for (auto& x : S) cout << x << '\n';
	}

}