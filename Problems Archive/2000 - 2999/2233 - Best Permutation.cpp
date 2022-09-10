#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

vector<int> res;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; res.resize(n);
		iota(res.begin(), res.end(), 0);
		reverse(res.begin() + (n & 1), res.begin() + n - 2);
		for (auto& x : res) cout << x + 1 << ' '; cout << '\n';
	}
}