#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<vector<int>> v;
map<int, pair<int, int>> m;
vector<int> sums;

int main() {
	int k; cin >> k; v.resize(k); sums.resize(k, 0);
	for (int i = 0; i < k; i++) {
		int n; cin >> n; v[i].resize(n);
		for (auto &x : v[i]) { cin >> x; sums[i] += x; }
	}
	bool b = false;
	for (int i = 0; i < k; i++) {
		int n = (int)v[i].size();
		for (int j = 0; j < n; j++) {
			int s = sums[i] - v[i][j];
			if (!m.count(s)) { m[s] = { i, j }; continue; }
			if (m[s].first == i) { continue; }

			b = true; cout << "YES" << endl;
			cout << i + 1 << ' ' << j + 1 << endl;
			cout << m[s].first + 1 << ' ' << m[s].second + 1 << endl;
			break;			
		}
		if (b) { break; }
	}
	if (!b) { cout << "NO" << endl; }
	cin.ignore(2); return 0;
}