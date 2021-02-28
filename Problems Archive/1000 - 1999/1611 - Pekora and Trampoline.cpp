#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> s, c;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; s.resize(n); 
		c.clear(); c.resize(n + 1, 0);
		for (auto& x : s) { cin >> x; }

		ll res = 0; for (int i = 0; i < n; i++) {
			if (s[i] == 1) { c[i + 1] += c[i]; continue; }

			if (i == n - 1) { s[i] -= c[i]; res += max(0, s[i] - 1); continue; }

			if (s[i] > n - 1 - i) {
				int d = s[i] - (n - 1 - i);
				if (c[i] >= d) { c[i] -= d; s[i] = n - 1 - i; }
				else { d -= c[i]; c[i] = 0; res += d; s[i] = n - 1 - i; }
			}

			for (int j = i + s[i]; j > i + 1; j--) {
				c[j]++; (c[i] == 0 ? res++ : c[i]--);
			}
			if (i + 1 != n) { c[i + 1] += c[i]; }
		}
		cout << res << '\n';
	}

	cin.ignore(2); return 0;
}