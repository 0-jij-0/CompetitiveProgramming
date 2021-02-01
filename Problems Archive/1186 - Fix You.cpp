#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int t; cin >> t; while (t--) {
		int n, m; cin >> n >> m;
		vector<string> v(n); int res = 0;
		for (auto &x : v) { cin >> x; }
		for (int i = 0; i < n; i++) res += v[i][m - 1] == 'R';
		for (int i = 0; i < m; i++) res += v[n - 1][i] == 'D';
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}