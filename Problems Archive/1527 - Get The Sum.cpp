#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> row, col;

int main() {
	freopen("sumgenerated.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; row.clear(); col.clear();
		row.resize(n, 1 << 30); col.resize(n, 0);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				int x; cin >> x;
				row[i] = min(row[i], x);
				col[j] = max(col[j], x);
			}

		ll res = 0;for (int i = 0; i < n; i++)
			res += (row[i] ^ col[i]);

		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}