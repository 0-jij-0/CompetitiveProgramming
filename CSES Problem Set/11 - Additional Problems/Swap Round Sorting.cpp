#include <bits/stdc++.h>
using namespace std;

vector<int> P;

void sortCycle(vector<int> C,vector<pair<int, int>>& swaps) {
	int N = (int)C.size();
	for (int i = 0, j = N - 1; i < j; i++, j--) {
		swaps.emplace_back(C[i], C[j]);
		swap(P[C[i]], P[C[j]]);
	}
}

vector<vector<int>> getCycles() {
	int n = (int)P.size();
	vector<int> vis(n, false);
	vector<vector<int>> cycles;
	for (int i = 0; i < n; i++) if (!vis[i]) {
		vector<int> cur(1, i);
		while (P[cur.back()] != i) cur.push_back(P[cur.back()]);
		for (auto& x : cur) vis[x] = true;
		cycles.emplace_back(cur);
	}

	return cycles;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; P.resize(n);
	for (auto& x : P) { cin >> x; --x; }

	vector<vector<pair<int, int>>> res;
	vector<vector<int>> cycles = getCycles();
	while (cycles.size() != n) {
		vector<pair<int, int>> swaps;
		for (auto& C : cycles) sortCycle(C, swaps);
		res.emplace_back(swaps);
		cycles = getCycles();
	}

	cout << res.size() << '\n'; for (auto& R : res) {
		cout << R.size() << '\n'; for (auto& [A, B] : R)
			cout << A + 1 << ' ' << B + 1 << '\n';
	}
}