#include <bits/stdc++.h>
using namespace std;

vector<int> A;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; A.resize(n);
	for (auto& x : A) cin >> x;
	sort(A.begin(), A.end());
	A.erase(unique(A.begin(), A.end()), A.end());
	int dup = n - (int)A.size(); n = (int)A.size();

	int L = 0, R = 1 << 30;
	while (L != R) {
		int M = (L + R + 1) >> 1;
		auto it = upper_bound(A.begin(), A.end(), M);
		int less = it - A.begin(), more = n - less;
		less + ((more + dup) / 2) >= M ? L = M : R = M - 1;
	}

	cout << L << '\n';
}