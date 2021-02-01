#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

vector<vector<int>> adj;
vector<int> p;
vector<vector<int>> D;
int n, m;

void allPairsShortestPath() {
	D.resize(n);
	for (int i = 0; i < n; i++) { D[i].resize(n); }

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i == j) { D[i][j] = 0; }
			else { D[i][j] = (adj[i][j] == 0) ? 1000000 : 1; }
		}

	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (D[i][k] + D[k][j] < D[i][j])
					D[i][j] = D[i][k] + D[k][j];
}

void min_len_subs() {
	vector<int> res; res.push_back(0);
	for (int i = 1; i < m; i++) {
		int last = res.back();
		if (D[p[last]][p[i]] == i - last) { continue; }
		res.push_back(i - 1);
	}
	res.push_back(m - 1); cout << res.size() << endl;
	for (int i = 0; i < (int)res.size(); i++) {
		cout << p[res[i]] + 1;
		if (i + 1 != res.size()) { cout << ' '; }
		else { cout << endl; }
	}	
}

int main() {
	cin >> n; adj.resize(n);
	for (int i = 0; i < n; i++) { adj[i].resize(n); }
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			char c; cin >> c; adj[i][j] = c - '0';
		}

	allPairsShortestPath();
	cin >> m; p.resize(m);
	for (int i = 0; i < m; i++) {
		int a; cin >> a; p[i] = a - 1;
	}
	min_len_subs();
	cin.ignore(2); return 0;
}