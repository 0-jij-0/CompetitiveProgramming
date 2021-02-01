#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> res;
vector<int> scores;

int main() {
	int n, m; cin >> n >> m; scores.resize(m);
	res.resize(m); for (int i = 0; i < m; i++) { res[i].resize(5, 0); }
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c; cin >> c; res[j][c - 'A']++;
		}
	}
	for (auto &x : scores) { cin >> x; }
	int max = 0;
	for (int i = 0; i < m; i++) {
		max += scores[i] * *max_element(res[i].begin(), res[i].end());
	}
	cout << max << endl;
	cin.ignore(2); return 0;
}