#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string s, t;


int main() {
	freopen("rev.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T; while (T--) {
		int n, m; cin >> n >> m >> s >> t;
		int r = m - n; string p = t.substr((r + 1) / 2, n);
		if (r & 1) { reverse(p.begin(), p.end()); }
		cout << (p == s ? "YES" : "NO") << '\n';
	}
}