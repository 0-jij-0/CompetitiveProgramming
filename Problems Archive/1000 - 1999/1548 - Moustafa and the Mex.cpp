#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("mex.in", "r", stdin);

	int t; cin >> t; while (t--) {
		int n, q; cin >> n >> q; v.resize(n);
		for (auto& x : v) { cin >> x; }
		vector<int> pref(n, v.front()); 
		vector<int> suf(n, v.back());

		for (int i = 1; i < n; i++) pref[i] = min(v[i], pref[i - 1]); 
		for (int i = n - 2; i >= 0; i--) suf[i] = min(v[i], suf[i + 1]);

		while (q--) {
			int l, r; cin >> l >> r; l--; r--;
			int left = l ? pref[l - 1] : (1 << 30);
			int right = r != n - 1 ? suf[r + 1] : (1 << 30);
			cout << min({ left, right, n + 1 }) << '\n';
		}
	}
	cin.ignore(2); return 0;
}