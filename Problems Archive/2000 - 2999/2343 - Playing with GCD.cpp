#include <bits/stdc++.h>
using namespace std;

vector<int> A;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; A.resize(n);
		for (auto& x : A) cin >> x;

		vector<int> B(n + 1); 
		B[0] = A[0]; B[n] = A[n - 1];
		for (int i = 1; i < n; i++)
			B[i] = lcm(A[i - 1], A[i]);

		bool ok = true;
		for (int i = 0; i < n && ok; i++)
			if (gcd(B[i], B[i + 1]) != A[i]) ok = false;

		cout << (ok ? "YES" : "NO") << '\n';
	}
}