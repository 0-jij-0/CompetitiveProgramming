#include <bits/stdc++.h>
using namespace std;

vector<int> A[10];

int findX(int i) {
	string s = to_string(i);
	sort(s.begin(), s.end());
	int res = 0, x = (int)s.size();
	for (int i = 1; i < x; i++)
		res = max(res, abs(s[i] - s[i - 1]));
	return res;
}

int main() {
	freopen("lucky.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for (int i = 1; i <= 1000000; i++)
		A[findX(i)].push_back(i);

	int q; cin >> q; while (q--) {
		int l, r, x; cin >> l >> r >> x; int res = 0;
		for (int i = 0; i <= min(x, 9); i++) {
			auto L = lower_bound(A[i].begin(), A[i].end(), l);
			auto R = upper_bound(A[i].begin(), A[i].end(), r);
			res += R - L;
		}

		cout << res << '\n';
	}
}