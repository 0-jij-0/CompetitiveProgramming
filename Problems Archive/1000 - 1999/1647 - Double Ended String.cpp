#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string a, b;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		cin >> a >> b; if (a.size() > b.size()) { swap(a, b); }
		int n = (int)a.size(), m = (int)b.size();

		int res = n + m; for (int i = 0; i < n; i++)
			for (int j = i; j < n; j++) {
				int len = j - i + 1; bool ok = false;
				for(int k = 0; k <= m - len; k++)
					if (a.substr(i, len) == b.substr(k, len)) { ok = true; break; }
				if (ok) { res = min(res, n + m - 2 * len); }
			}
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}