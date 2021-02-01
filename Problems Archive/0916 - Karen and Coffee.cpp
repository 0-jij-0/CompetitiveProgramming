#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k, q; cin >> n >> k >> q;
	vector<int> v(200002, 0);
	while (n--) { int l, r; cin >> l >> r; v[l]++; v[r + 1]--; }
	partial_sum(v.begin(), v.end(), v.begin());
	for (auto &x : v) { x = (x >= k); }
	partial_sum(v.begin(), v.end(), v.begin());

	while (q--) { int a, b; cin >> a >> b; cout << v[b] - v[a - 1] << '\n'; }
	cin.ignore(2); return 0;
}