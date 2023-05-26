#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> A;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; A.resize(n);
		for (auto& x : A) { cin >> x; }
		sort(A.begin(), A.end());
		for (int i = 1; i < n && A[i] < 0; i += 2) {
			A[i] *= -1; A[i - 1] *= -1;
		}
		sort(A.begin(), A.end());
		if (-A[0] > A[1]) { A[0] *= -1; A[1] *= -1; }
		cout << accumulate(A.begin(), A.end(), 0ll) << '\n';
	}
}