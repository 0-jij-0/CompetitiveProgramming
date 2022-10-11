#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

vector<int> A;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; A.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> A[i]; A[i] -= i + 1;
		}

		ll res = 0;
		for (int i = 0, j = 0; i < n; i++) {
			while (j < n && A[j] + i >= 0) { j++; }
			res += j - i;
		}

		cout << res << '\n';
	}
}