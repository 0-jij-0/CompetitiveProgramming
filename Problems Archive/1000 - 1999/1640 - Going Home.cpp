#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> v, idx;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; v.resize(n);
	for (auto& x : v) { cin >> x; }
	map<int, vector<pair<int, int>>> m;

	n = min(n, 4000); v.resize(n);
	for (int i = 0; i < n - 1; i++)	for (int j = i + 1; j < n; j++) {
		for (auto& p : m[v[i] + v[j]]) {
			if (i == p.first || i == p.second) { continue; }
			if (j == p.first || j == p.second) { continue; }
			cout << "YES\n" << i + 1 << ' ' << j + 1 << ' ';
			cout << p.first + 1 << ' ' << p.second + 1 << '\n';
			cin.ignore(2); return 0;
		}
		m[v[i] + v[j]].emplace_back(i, j);
	}

	cout << "NO\n";
	cin.ignore(2); return 0;
}