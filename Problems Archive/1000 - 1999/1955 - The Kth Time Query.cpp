#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, vector<int>> m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, q; cin >> n >> q;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		m[x].push_back(i + 1);
	}

	while (q--) {
		int x, k; cin >> x >> k;
		if (m[x].size() < k) { cout << -1 << '\n'; continue; }
		cout << m[x][k - 1] << '\n';
	}

	cin.ignore(2); return 0;
}