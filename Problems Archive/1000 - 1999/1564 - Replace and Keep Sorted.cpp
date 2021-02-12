#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, q, k; cin >> n >> q >> k; v.resize(n);
	for (auto& x : v) { cin >> x; }

	while (q--) {
		int l, r; cin >> l >> r; l--; r--;
		int res = k + v[r] - v[l] - ((r - l) << 1) - 1;
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}