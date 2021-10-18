#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, m; cin >> n >> m; v.clear(); v.resize(n, 0);
		for (int i = 0; i < m; i++) {
			int a, b, c; cin >> a >> b >> c; v[--b] = 1;
		}
		int r = find(v.begin(), v.end(), 0) - v.begin();
		for (int i = 0; i < n; i++) if (i != r) {
			cout << i + 1 << ' ' << r + 1 << '\n';
		}
	}
	cin.ignore(2); return 0;
}