#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; int res = 0;
		vector<int> primeFact(30, 1);
		for (int p = 2; p * p <= n; p++) if (n % p == 0) {
			int e = 0; while (n % p == 0) { ++e; n /= p; }
			for (int i = 0; i < e; i++) primeFact[i] *= p;
		}
		if (n != 1) primeFact[0] *= n;
		cout << accumulate(primeFact.begin(), find(primeFact.begin(), primeFact.end(), 1), 0) << '\n';
	}
}