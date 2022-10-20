#include <bits/stdc++.h>
using namespace std;

vector<int> A;

bool check(int k) {
	int r = 1, n = (int)A.size();

	for (int j = n - 1, i = 0; j >= i; j--) {
		if (A[j] > k + 1 - r) continue;
		r++; i++;
	}

	return r > k;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; A.resize(n);
		for (auto& x : A) cin >> x;
		sort(A.begin(), A.end());

		int res = 0;
		for (int i = 1; i <= (n + 1) / 2; i++)
			if (check(i)) res = i;

		cout << res << '\n';
	}
}