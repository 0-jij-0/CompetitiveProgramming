#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;

int main() {
	int n, k; cin >> n >> k; v.resize(k);
	int res = 0; int j = 1;
	for (int i = 0; i < k; i++) {
		int m; cin >> m; v[i].resize(m);
		for (auto &x : v[i]) { cin >> x; }
		if (v[i][0] == 1) {
			while (j < m && v[i][j] == v[i][j - 1] + 1) { j++; }
			res += m - j; continue;
		}
		res += m - 1;
	}
	res += n - j; cout << res << endl;
	cin.ignore(2); return 0;
}