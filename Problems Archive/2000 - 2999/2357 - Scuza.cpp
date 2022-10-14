#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> A;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, q; cin >> n >> q; A.resize(n);
		for (auto& x : A) cin >> x;

		vector<int> prefMax = A; vector<ll> prefSum(A.begin(), A.end());
		partial_sum(prefSum.begin(), prefSum.end(), prefSum.begin());
		partial_sum(prefMax.begin(), prefMax.end(), prefMax.begin(), [&](int x, int y) { return max(x, y); });

		while (q--) {
			int k; cin >> k; int L = 0, R = n - 1;
			if (k < A[0]) { cout << "0 "; continue; }

			while (L != R) {
				int M = (L + R + 1) >> 1;
				prefMax[M] <= k ? L = M : R = M - 1;
			}

			cout << prefSum[L] << ' ';
		}
		cout << '\n';
	}
}