#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

struct Graph {
	vector<vector<int>> nodes; int n;
	vector<int> MEX;
	Graph(int _n) : MEX(_n), n(_n), nodes(_n) {}

	void addEdge(int u, int v) {
		nodes[u].emplace_back(v);
	}

	void precomputeMEX() {
		for (int i = n - 1; i >= 0; i--) {
			vector<int> freq(7);
			for (int& e : nodes[i]) freq[MEX[e]] = 1;
			MEX[i] = find(freq.begin(), freq.end(), 0) - freq.begin();
		}
	}
};

vector<string> A; int N, M;
int di[3] = { 1, 3, 5 }, dj[3] = { 1, 2, 3 };

bool checkHorizontal(int i, int j, int k) {
	if (j + k >= M) { return false; }
	bool ok = true;
	for (int x = 1; x <= k; x++)
		ok = ok && A[i][j + x] == 'W';
	return ok;
}

bool checkVertical(int i, int j, int k) {
	return i + k < N && A[i + k][j] == 'W';
}

int main() {
	freopen("roger.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T; while (T--) {
		int Q; cin >> N >> M >> Q; 
		A.resize(N); Graph G(N * M);
		for (auto& x : A) cin >> x;

		for(int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) if (A[i][j] == 'W')
				for (int k = 0; k < 3; k++) {
					if (checkHorizontal(i, j, dj[k])) G.addEdge(i * M + j, i * M + j + dj[k]);
					if (checkVertical(i, j, di[k])) G.addEdge(i * M + j, (i + di[k]) * M + j);
				}

		G.precomputeMEX(); while (Q--) {
			int K, res = 0; cin >> K; while (K--) {
				int x, y; cin >> x >> y;
				res ^= G.MEX[--x * M + --y];
			}

			cout << (res ? "Roger" : "Rafael") << '\n';
		}
	}
}