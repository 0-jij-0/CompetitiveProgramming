#include <bits/stdc++.h>
using namespace std;

vector<int> A;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; A.resize(n);
		for (auto& x : A) cin >> x;
		int sum = accumulate(A.begin(), A.end(), 0);
		int res = sum - 4;
		for (int i = 1; i < n; i++) {
			if (A[i] == -1 && A[i - 1] == -1) { res = max(res, sum + 4); }
			if (A[i] + A[i - 1] == 0) { res = max(res, sum); }
		}
		cout << res << '\n';
	}
}