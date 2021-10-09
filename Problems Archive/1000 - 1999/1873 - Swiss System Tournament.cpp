#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
vector<string> A;

bool compare(pair<int, int>& p1, pair<int, int>& p2) {
	if (p1.first != p2.first) { return p1.first > p2.first; }
	return p1.second < p2.second;
}

bool win(int r, int i, int j) {
	if (A[i][r] == 'G' && A[j][r] == 'C') { return true; }
	if (A[i][r] == 'P' && A[j][r] == 'G') { return true; }
	if (A[i][r] == 'C' && A[j][r] == 'P') { return true; }
	return false;
}

int main() {
	int n, m; cin >> n >> m; n <<= 1;
	v.resize(n); A.resize(n);
	for (auto& x : A) cin >> x;

	for (int i = 0; i < n; i++) v[i] = { 0, i };

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j += 2) {
			if (A[v[j].second][i] == A[v[j + 1].second][i]) { continue; }
			if (win(i, v[j].second, v[j + 1].second)) { v[j].first++; }
			else { v[j + 1].first++; }
		}
		sort(v.begin(), v.end(), compare);
	}

	for (auto& x : v) cout << x.second + 1 << '\n';
	cin.ignore(2); return 0;
}