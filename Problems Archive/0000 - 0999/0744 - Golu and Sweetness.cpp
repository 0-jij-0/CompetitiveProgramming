#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

vector<int> v;

int main() {
	int n, q; cin >> n >> q; v.resize(n);
	for (auto &x : v) { cin >> x; x = (x == 3) || (x == 4) || (x == 6); }
	partial_sum(v.begin(), v.end(), v.begin());
	while (q--) {
		int l, r; cin >> l >> r; l--; r--;
		cout << v[r] - (l ? v[l - 1] : 0) << '\n';
	}
	cin.ignore(2); return 0;
}