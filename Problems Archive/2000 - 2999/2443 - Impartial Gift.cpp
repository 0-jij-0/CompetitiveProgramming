#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> A, B;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M; ll D; cin >> N >> M >> D;
	A.resize(N); for (auto& x : A) cin >> x;
	B.resize(M); for (auto& x : B) cin >> x;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	
	ll res = -1;
	for (int i = 0, j = 0; i < N; ++i) {
		while (j < M && B[j] - A[i] <= D) ++j;
		if (j && abs(B[j - 1] - A[i]) <= D) res = A[i] + B[j - 1];
	}
	cout << res << '\n';

}