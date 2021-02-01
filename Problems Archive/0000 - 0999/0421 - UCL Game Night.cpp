#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main() {
	int T; cin >> T;
	while (T--) {
		int N, M, K; cin >> N >> M >> K;
		vector<vector<int>> grid(N), ones(N);

		for (int i = 0; i < N; i++) {
			grid[i].resize(M); ones[i].resize(M, 0);
			for (int j = 0; j < M; j++)
				cin >> grid[i][j];
		}
		
		for (int j = 0; j < M; j++) {
			ones[0][j] = grid[0][j];
			for (int i = 1; i < N; i++)
				ones[i][j] = ones[i - 1][j] + grid[i][j];
		}

		int res = 0; vector<int> linear(M);
		for (int y2 = 0; y2 < M; y2++) {
			for (int y1 = y2; y1 < M; y1++) {			
				for (int j = 0; j < M; j++) {
					if (!y2) { linear[j] = ones[y1][j]; }
					else { linear[j] = ones[y1][j] - ones[y2 - 1][j]; }
				}

				vector<int> partial(M), minSufIndex(M, -1);
				partial_sum(linear.begin(), linear.end(), partial.begin());

				int minSuf = partial.back();
				minSufIndex[M - 1] = M - 1;
				for (int k = M - 2; k >= 0; k--) {
					if (partial[k] < minSuf) { minSufIndex[k] = k; minSuf = partial[k]; }
					else { minSufIndex[k] = minSufIndex[k + 1]; }
				}

				int a = 0, b = minSufIndex[0], h = y1 - y2 + 1;
				while (a <= b) {
					int cur = partial[b] - partial[a];
					if (cur <= K && b+1 < M) { res = max(res, h*cur); b = minSufIndex[b + 1]; }
					else { a++; }
				}
			}
		}
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}