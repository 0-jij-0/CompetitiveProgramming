#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> v;
vector<int> score;

int findScore(vector<int> & v) {
	int i = 0, j = 0, n = (int)v.size();
	int res = 0;
	while (j != n) {
		if (!v[i]) { i = j = j + 1; continue; }
		if (v[j]) { j++; continue; }
		res = max(res, j - i); i = j;
	}
	return max(res, n - i);
}

int main() {
	int n, m, q; cin >> n >> m >> q;
	v.resize(n, vector<int>(m)); score.resize(n);
	for (auto &x : v) for (auto &y : x) { cin >> y; }
	for (int i = 0; i < n; i++) { score[i] = findScore(v[i]); }
	while (q--) {
		int i, j; cin >> i >> j; i--; j--;
		v[i][j] = v[i][j] ? 0 : 1;
		score[i] = findScore(v[i]);
		cout << *max_element(score.begin(), score.end()) << endl;
	}
	cin.ignore(2); return 0;
}