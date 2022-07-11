#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<map<int, int>> v;
map<int, map<int, int>> freq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; v.resize(n);
	for (int i = 0; i < n; i++) {
		int m; cin >> m; while (m--) {
			int p, e; cin >> p >> e;
			v[i][p] = e; freq[p][e]++;
		}
	}

	bool still = false; int res = 0;
	for (int i = 0; i < n; i++) {
		bool change = false; for (auto& x : v[i])  if(freq[x.first][x.second] == 1)
			if (x.second == freq[x.first].rbegin()->first) { change = true; break; }
		change ? res++ : still = true;
	}

	cout << res + still << '\n';
}