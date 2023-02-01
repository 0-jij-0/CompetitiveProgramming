#include <bits/stdc++.h>
using namespace std;

vector<int> P, A, idx;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t; while (t--) {
		int n, m, d; cin >> n >> m >> d; idx.resize(n);
		P.resize(n); for (int i = 0; i < n; i++) { cin >> P[i]; idx[--P[i]] = i; }
		A.resize(m); for (auto& x : A) { cin >> x; --x; }

		int res = n;
		for (int i = 1; i < m; i++) {
			if (idx[A[i]] < idx[A[i - 1]]) { res = 0; break; }
			if (idx[A[i]] > idx[A[i - 1]] + d) { res = 0; break; }
			int curDiff = idx[A[i]] - idx[A[i - 1]];
			res = min({ res, idx[A[i]] - idx[A[i - 1]], 
						(d < n - 1) ? d + 1 - curDiff : n + 1 });
		}

		cout << res << '\n';
	}
}