#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, m; cin >> n >> m; 
		v.clear(); v.resize(m);
		for (int i = 0; i < n; i++) {
			int x; cin >> x; v[x % m]++;
		}
		int res = (v[0] != 0);
		int i = 1, j = m - 1; while (i < j) {
			int ma = max(v[i], v[j]);
			int mi = min(v[i], v[j]);
			if (ma == 0) { i++; j--; continue; }
			if (mi == 0) { res += ma; i++; j--; continue; }
			int rem = ma - mi - 1; i++; j--;
			res += 1 + max(0, rem);
		}
		if (i == j && v[i]) { res++; }
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}