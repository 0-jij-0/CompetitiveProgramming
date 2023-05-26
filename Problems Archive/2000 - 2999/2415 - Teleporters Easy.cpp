#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> A;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t; while (t--) {
		int n, c; cin >> n >> c; A.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> A[i]; A[i] += i + 1;
		}
		sort(A.begin(), A.end());
		partial_sum(A.begin(), A.end(), A.begin());
		cout << upper_bound(A.begin(), A.end(), c) - A.begin() << '\n';
	}
}