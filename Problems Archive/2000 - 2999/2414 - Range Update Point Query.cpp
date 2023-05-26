#include <bits/stdc++.h>
using namespace std;

vector<int> A;

int sumDigits(int x) {
	int res = 0;
	for (; x; x /= 10) res += x % 10;
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t; while (t--) {
		int n, q; cin >> n >> q; A.resize(n); set<int> active;
		for (int i = 0; i < n; i++) {
			cin >> A[i]; if (A[i] > 9) active.insert(i);
		}

		while (q--) {
			int t; cin >> t; if (--t) {
				int x; cin >> x; cout << A[--x] << '\n';
			}
			else {
				int l, r; cin >> l >> r;
				auto it = active.lower_bound(--l);
				set<int> inactive;
				while (it != active.end() && *it < r) {
					int cur = *it, s = sumDigits(A[cur]);
					if (s < 10) inactive.insert(cur);
					A[cur] = s; it++;
				}
				for (auto& x : inactive) active.erase(x);
			}
		}
	}
}