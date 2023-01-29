#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> A;
ll DP[200000][2];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	DP[0][0] = DP[0][1] = 0;
	int t; cin >> t; while (t--) {
		int n, s; cin >> n >> s; A.resize(n);
		for (auto& x : A) cin >> x;

		vector<array<ll, 2>> P(n);
		P[0] = { A[0], A[0] }; P[n - 1] = { A[n - 1], A[n - 1] };
		for (int i = 1; i < n - 1; i++) {
			if (A[i] > s) P[i] = { s, A[i] - s };
			else P[i] = { 0, A[i] };
		}

		DP[1][0] = DP[1][1] = A[0] * A[1];
		for (int i = 2; i < n; i++) {
			ll temp0 = min(DP[i - 1][0] - P[i - 2][0] * P[i - 1][0], DP[i - 1][1] - P[i - 2][1] * P[i - 1][0]);
			ll temp1 = min(DP[i - 1][0] - P[i - 2][0] * P[i - 1][1], DP[i - 1][1] - P[i - 2][1] * P[i - 1][1]);
			DP[i][0] = A[i] * P[i - 1][0] + temp0;
			DP[i][1] = A[i] * P[i - 1][1] + temp1;
		}
		cout << min(DP[n - 1][0], DP[n - 1][1]) << '\n';
	}
}