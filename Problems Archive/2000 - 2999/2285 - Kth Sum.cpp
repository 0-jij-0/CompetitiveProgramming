#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> A, B; int n; ll k;

bool check(int M) {
	ll res = 0;
	for (int i = 0, j = n - 1; i < n && j >= 0; i++) {
		while (j >= 0 && A[i] + B[j] >= M) { j--; }
		res += j + 1;
	}
	return res < k;
}

int findKth() {
	int L = A[0] + B[0], R = A[n - 1] + B[n - 1];
	while (L != R) {
		int M = (L + R + 1) >> 1;
		check(M) ? L = M : R = M - 1;
	}
	return L;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k; A.resize(n); B.resize(n);
	for (auto& x : A) cin >> x;
	for (auto& x : B) cin >> x;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	cout << findKth() << '\n';
}